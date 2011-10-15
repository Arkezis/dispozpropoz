/*
 * SearchForm.cpp
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#include "SearchForm.h"

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

	// TODO: Add your initialization code here

	// Get a button via resource ID
	/*
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
	if (__pButtonOk != null)
	{
		__pButtonOk->SetActionId(ID_BUTTON_OK);
		__pButtonOk->AddActionEventListener(*this);
	}
	*/
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

	pCheckButton4 = static_cast<CheckButton *>(GetControl(L"IDC_CHECKBUTTON4"));
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

	/* svj: stopping here
	pFooterItem = static_cast<FooterItem *>(GetControl(L"ID_FOOTERITEM1"));
	if (pFooterItem != null) {
		pFooterItem->SetActionId(ID_BUTTON_SEARCH);
		pFooterItem->AddTouchEventListener(*this);
		pFooterItem->AddActionEventListener(*this);
	}
	*/

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
	/*case ID_BUTTON_OK:
		{
			AppLog("OK Button is clicked! \n");
		}
		break;
	*/
	default:
		break;
	}

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
