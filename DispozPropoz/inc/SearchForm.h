/*
 * SearchForm.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#ifndef SEARCHFORM_H_
#define SEARCHFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

class SearchForm  :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener {

public:
	SearchForm();
	virtual ~SearchForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif /* SEARCHFORM_H_ */
