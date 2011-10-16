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


