#include "Form1.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Base::Collection;
Form1::Form1(void)
{
}

Form1::~Form1(void)
{
}

bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");

	__cjp = new CALJsonParser();
	__cjp->setJSONparserListener((Form*)this);

	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Get a button via resource ID
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
	if (__pButtonOk != null)
	{
		__pButtonOk->SetActionId(ID_BUTTON_OK);
		__pButtonOk->AddActionEventListener(*this);
	}

	return r;
}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Form1::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_OK:
		{
			AppLog("OK Button is clicked! \n");

			String host(L"http://cilheo.fr");
			String uri(L"http://cilheo.fr/propoz.php?action=list&X=254&Y=32&range=2555&contains=toto");
			__cjp->PerformJSON(host, uri);

		}
		break;
	default:
		break;
	}
}

void
Form1::onJSONparsingTerminated(){
	ArrayList* aKey = __cjp->getKeyList();
	IList* aValue = __cjp->getValueList();

	AppLog("%s",(String*)aKey->GetAt(0));
	AppLog("%s",(String*)aValue->GetAt(0));
}

