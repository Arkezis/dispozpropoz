/*
 * InfoForm.h
 *
 *  Created on: 16 Oct 2011
 *      Author: vj
 */

#ifndef INFOFORM_H_
#define INFOFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include "FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

class InfoForm  :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public Osp::Ui::Controls::IFormBackEventListener
	{
public:
	InfoForm();
	virtual ~InfoForm();
	bool Initialize(void);

// Implementation
protected:
	static const int ID_SCROLLPANEL = 101;
	Osp::Ui::Controls::ScrollPanel *__pScrollPanel;

	static const int ID_HEADER_ABOUT_BUTTON = 501;
	Osp::Ui::Controls::MessageBox msgBoxAbout;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
};

#endif /* INFOFORM_H_ */
