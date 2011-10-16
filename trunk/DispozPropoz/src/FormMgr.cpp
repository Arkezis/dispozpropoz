#include "FormMgr.h"
#include "Form1.h"
#include "SearchForm.h"
#include "FormPropoz.h"
#include "FormDispoz.h"
#include "FormDetails.h"
#include "InfoForm.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

/* Using FormMgr :
 * In a listener :
 * Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

	FormMgr *pFormMgr = static_cast<FormMgr *>(pFrame->GetControl("FormMgr"));
	if(null == pFormMgr){
		AppLog("pFormMgr == null \n");
	}else{
		pFormMgr->SendUserEvent(FormMgr::REQUEST_XXXXXXXXXX , null); // in place of null, you can place an IList for the args
	}

 */


FormMgr::FormMgr(void) :
__prevForm(null)
{
}

FormMgr::~FormMgr(void)
{
}

bool
FormMgr::Initialize()
{
	Form::Construct(FORM_STYLE_NORMAL);
	SetName(L"FormMgr");
	return true;
}

void
FormMgr::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	AppLog("Dans le form MGR");
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

	switch(requestId)
	{
		case REQUEST_LISTDISPOZ:
		{
			AppLog("C'est parti pour la liste");
			FormDispoz *listDispozForm = new FormDispoz();
			listDispozForm->Initialize();
			AppLog("Avant args");

			if (pArgs==null){
				pArgs = new Osp::Base::Collection::LinkedList();
				pArgs->Add(*(new String("")));
				pArgs->Add(*(new String("-1")));
			}

				String* arg1 = ((String*)pArgs->GetAt(0));
				String* arg2 = ((String*)pArgs->GetAt(1));

				listDispozForm->populateWithParams(arg1,arg2);

			AppLog("Après args");
			pFrame->AddControl(*listDispozForm);
			AppLog("Après args");
			pFrame->SetCurrentForm(*listDispozForm);
			AppLog("Après args");
			pFrame->RequestRedraw();
			AppLog("Après args4");
			if (null != __prevForm){
				AppLog("Après args3");
				//pFrame->RemoveControl(*__prevForm);
				AppLog("Après args2");
			}
			AppLog("Après args1");
			__prevForm = listDispozForm;
			AppLog("Après args");
		}
		break;

		case REQUEST_SEARCHDISPOZ:
		{
			SearchForm* searchForm = new SearchForm();
			searchForm->Initialize();
			pFrame->AddControl(*searchForm);
			pFrame->SetCurrentForm(*searchForm);
			searchForm->RequestRedraw();
			if (null != __prevForm)
				pFrame->RemoveControl(*__prevForm);
			__prevForm = searchForm;

		}
		break;
		case REQUEST_PROPOZ:
		{
			FormPropoz* propozForm = new FormPropoz();
			propozForm->Initialize();
			pFrame->AddControl(*propozForm);
			pFrame->SetCurrentForm(*propozForm);
			propozForm->RequestRedraw();
			if (null != __prevForm)
				pFrame->RemoveControl(*__prevForm);
			__prevForm = propozForm;
		}
		break;
		case REQUEST_PROFILE:
			{

				InfoForm* profileForm = new InfoForm();
				profileForm->Initialize();
				pFrame->AddControl(*profileForm);
				pFrame->SetCurrentForm(*profileForm);
				profileForm->RequestRedraw();
				if (null != __prevForm)
					pFrame->RemoveControl(*__prevForm);
				__prevForm = profileForm;

			}
			break;
		case REQUEST_DETAILSDISPOZ:
			{

				FormDetails* formDetails = new FormDetails();
				formDetails->Initialize();
				pFrame->AddControl(*formDetails);
				pFrame->SetCurrentForm(*formDetails);
				formDetails->RequestRedraw();
				if (null != __prevForm)
					pFrame->RemoveControl(*__prevForm);
				__prevForm = formDetails;

			}
			break;
		default:
			break;
	}
}
