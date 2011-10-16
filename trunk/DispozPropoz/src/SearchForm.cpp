/*
 * SearchForm.cpp
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#include "SearchForm.h"
#include "FormMgr.h"
SearchForm::SearchForm() {
	// TODO Auto-generated constructor stub

}

SearchForm::~SearchForm() {
	// TODO Auto-generated destructor stub
}


bool
SearchForm::Initialize()
{
	// Construct an XML form
	Construct(L"SEARCH_FORM");

	return true;
}

result
SearchForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	pSearchBar = static_cast<SearchBar *>(GetControl(L"IDC_SEARCHBAR1"));
	if (pSearchBar != null)
	{
		//pSearchBar->SetActionId(ID_SEARCHBAR);
		pSearchBar->AddActionEventListener(*this);
	}

	pCheckButton1 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON1"));
	if (pCheckButton1 != null)
	{
		//pCheckButton1->SetActionId(ID_CHECKBUTTON_1);
		pCheckButton1->AddActionEventListener(*this);
	}

	pCheckButton2 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON2"));
	if (pCheckButton2 != null)
	{
		//pCheckButton2->SetActionId(ID_CHECKBUTTON_2);
		pCheckButton2->AddActionEventListener(*this);
	}

	pCheckButton3 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON3"));
	if (pCheckButton3 != null)
	{
		//pCheckButton3->SetActionId(ID_CHECKBUTTON_3);
		pCheckButton3->AddActionEventListener(*this);
	}

	pCheckButton4 = static_cast<CheckButton *>(GetControl(L"IDC_CHE	CKBUTTON4"));
	if (pCheckButton4 != null)
	{
		//pCheckButton4->SetActionId(ID_CHECKBUTTON_4);
		pCheckButton4->AddActionEventListener(*this);
	}

	pCheckButton5 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON5"));
	if (pCheckButton5 != null)
	{
		//pCheckButton5->SetActionId(ID_CHECKBUTTON_5);
		pCheckButton5->AddActionEventListener(*this);
	}

	pCheckButton6 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON6"));
	if (pCheckButton6 != null)
	{
		//pCheckButton6->SetActionId(ID_CHECKBUTTON_6);
		pCheckButton6->AddActionEventListener(*this);
	}

	RadioGroup* radioGroupObj = new RadioGroup();
	radioGroupObj->Construct();
	/*radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON1")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON2")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON3")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON4")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON5")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON6")));
	*/

	radioGroupObj->Add(*pCheckButton1);
	radioGroupObj->Add(*pCheckButton2);
	radioGroupObj->Add(*pCheckButton3);
	radioGroupObj->Add(*pCheckButton4);
	radioGroupObj->Add(*pCheckButton5);
	radioGroupObj->Add(*pCheckButton6);

	Footer* pFooter = GetFooter();
	if(pFooter)
	{
		FooterItem  footerItemCreate;
		footerItemCreate.Construct(ID_FOOTERITEM1);
		footerItemCreate.SetText("Recherche");
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->AddItem(footerItemCreate);
		pFooter->SetBackButton();
		pFooter->AddActionEventListener(*this);
		SetFormBackEventListener(this);
	}

	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Dispoz'");

		ButtonItem buttonItem;
		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_ABOUT_BUTTON);
		AppResource *pAppResource = Application::GetInstance()->GetAppResource();
		Bitmap* __pBitmap = null;

		//TODO: use another icon instead of this
		if (pAppResource)
			__pBitmap = pAppResource->GetBitmapN(L"boisson.jpg", BITMAP_PIXEL_FORMAT_ARGB8888);
		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
		pHeader->SetButton(BUTTON_POSITION_RIGHT, buttonItem);
		pHeader->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0x87,0xCD,0x4F));
		pHeader->AddActionEventListener(*this);
	}
	return r;
}

result
SearchForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
SearchForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_SEARCHBAR:
		{

		}
		break;

	case ID_CHECKBUTTON_1:
	{
		//if( static_cast<CheckButton>(source).IsSelected()== true)   AppLog("OK Button is clicked! \n");
	}
		break;

	case ID_FOOTERITEM1:
	{
		Osp::Base::Collection::IList* args = new Osp::Base::Collection::LinkedList();
		categorySelected=-1;
		if(pCheckButton1->IsSelected()) categorySelected =0;
		else if(pCheckButton2->IsSelected()) categorySelected =1;
		else if(pCheckButton3->IsSelected()) categorySelected =2;
		else if(pCheckButton4->IsSelected()) categorySelected =3;
		else if(pCheckButton5->IsSelected()) categorySelected =4;
		else if(pCheckButton6->IsSelected()) categorySelected =5;
		textEntered = pSearchBar->GetText();

		Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
		FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
		if(pFormMgr == null)	return;

		if(textEntered.CompareTo("")>0 || textEntered.CompareTo("")<0 )	args->Add(textEntered);
		if(categorySelected.CompareTo(-1)>0){
			args->Add(categorySelected.ToString());
			AppLog("Search categ : %d \n",categorySelected.ToInt());
		}
		pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, args);

	}
	case ID_HEADER_ABOUT_BUTTON:
	{
		msgBoxAbout.Construct("About","Blah blah blah",MSGBOX_STYLE_OK ,0);
		int modalResult = 0;
		msgBoxAbout.ShowAndWait(modalResult);
		break;
	}
	default:
		break;
	}

}

void
SearchForm::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));

	if(pFormMgr == null)
			return;
	pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, null);
}

void
SearchForm::OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
SearchForm::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}
