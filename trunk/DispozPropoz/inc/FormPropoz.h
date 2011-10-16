#ifndef _FORMPROPOZ_H_
#define _FORMPROPOZ_H_

#include <FBase.h>
#include <FUi.h>

class FormPropoz :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public Osp::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	FormPropoz(void);
	virtual ~FormPropoz(void);
	bool Initialize(void);

// Implementation
protected:


public:

	static const int ID_BUTTON_ADD = 100;
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);

};

#endif	//_FORMPROPOZ_H_
