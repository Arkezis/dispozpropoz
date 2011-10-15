#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include "CALJsonParser.h"

class Form1 :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public CALJsonParser
{

// Construction
public:
	Form1(void);
	virtual ~Form1(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_OK = 101;
	Osp::Ui::Controls::Button *__pButtonOk;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	//Implememtnation du listener
	void onJSONparsingTerminated();

private:
	CALJsonParser* __cjp;
};

#endif	//_FORM1_H_
