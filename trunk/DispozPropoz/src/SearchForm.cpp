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

	RadioGroup* radioGroupObj = new RadioGroup();
	radioGroupObj->Construct();
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON1")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON2")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON3")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON4")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON5")));
	radioGroupObj->Add(*static_cast<CheckButton*>(GetControl(L"IDC_CHECKBUTTON6")));

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
