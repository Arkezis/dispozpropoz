#include "FormPropoz.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

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

	default:
		break;
	}
}


