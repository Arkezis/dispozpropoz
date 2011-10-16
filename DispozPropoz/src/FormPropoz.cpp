#include "FormPropoz.h"
#include "FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

FormPropoz::FormPropoz(void)
{
}

FormPropoz::~FormPropoz(void)
{
}

bool
FormPropoz::Initialize()
{
	// Construct an XML form
	Construct(L"FormPropoz");

	return true;
}

result
FormPropoz::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header * pHeader = GetHeader();
		if(pHeader){
			pHeader->SetColor(Color(0x87,0xCD,0x4F));
			pHeader->SetTitleText(L"Propoz'");
		}

		Footer* pFooter = GetFooter();
		if(pFooter)
		{
			pFooter->SetColor(Color(0xF2,0xE7,0xE4));
			pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
			pFooter->SetButtonColor(BUTTON_ITEM_STATUS_DISABLED,Color(0xE5,0xCE,0xCB));
			pFooter->SetButtonColor(BUTTON_ITEM_STATUS_HIGHLIGHTED,Color(0xE5,0xCE,0xCB));
			pFooter->SetButtonColor(BUTTON_ITEM_STATUS_PRESSED,Color(0xE5,0xCE,0xCB));
			pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
			pFooter->SetItemColor(FOOTER_ITEM_STATUS_DISABLED,Color(0xE5,0xCE,0xCB));
			pFooter->SetItemColor(FOOTER_ITEM_STATUS_HIGHLIGHTED,Color(0xE5,0xCE,0xCB));
			pFooter->SetItemColor(FOOTER_ITEM_STATUS_PRESSED,Color(0xE5,0xCE,0xCB));
			FooterItem  footerItemCreate;
			footerItemCreate.Construct(ID_BUTTON_ADD);
			footerItemCreate.SetText("Ajouter");
			pFooter->AddItem(footerItemCreate);
			pFooter->SetBackButton();
			pFooter->AddActionEventListener(*this);
			SetFormBackEventListener(this);
		}


		//Mapping des trucs a ecrire
		pName = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_PRODUCTNAME"));
		pQuantity = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_QUANTITY"));
		pUnit = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_UNIT"));
		pDate = static_cast<EditDate *>(GetControl(L"IDC_EDITDATE_PEREMPT"));
		//On met la date a aujourd'hui
        if(pDate!=null){
        	pDate->SetCurrentDate();
        }


	return r;
}

result
FormPropoz::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
FormPropoz::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
		case ID_BUTTON_ADD:
		{

			String pn(pName->GetText());
			String pq(pQuantity->GetText());
			String pu(pUnit->GetText());
			DateTime dt(pDate->GetDate());
			String sdt(dt.ToString());

			DateTime date;
			Osp::System::SystemTime::GetCurrentTime(date);
			if(pDate->GetDate().CompareTo(date)<0){
				//TODO mettre une popup si le mec met une date plus tot
				Osp::Ui::Controls::MessageBox* msgB = new MessageBox();
				msgB->Construct(L"Problème de date",L"Impossible de mettre une date antérieure à aujoud\'hui",MSGBOX_STYLE_OK  ,0);
				return;
			}

			if(pn.IsEmpty() || pq.IsEmpty() || pu.IsEmpty()){
				//TODO ajouter message box pour dire qu'il y a quelque chose de vide...
				Osp::Ui::Controls::MessageBox* msgB = new MessageBox();
				msgB->Construct(L"Champs vide",L"Tous les champs doivent être remplis",MSGBOX_STYLE_OK  ,0);
				return;
			}

			Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
			FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
			if(pFormMgr == null)	return;
			pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, null);
		}
		break;
	default:
		break;
	}
}

void FormPropoz::OnFormBackRequested(Osp::Ui::Controls::Form& source){
		AppLog("Je back");
		Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
		FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
		if(pFormMgr == null)
				return;
		pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, null);
}


