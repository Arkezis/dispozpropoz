#ifndef _FORMDETAILS_H_
#define _FORMDETAILS_H_

#include <FBase.h>
#include <FUi.h>

class FormDetails :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::ITouchEventListener
{

// Construction
public:
	FormDetails(void);
	virtual ~FormDetails(void);
	bool Initialize(void);
	static const int ID_FOOTERITEM1 = 101;

// Implementation
protected:
	//static const int ID_BUTTON_OK = 101;
	//Osp::Ui::Controls::Button *__pButtonOk;
	//static const int ID_SCROLLPANEL = 101;
	//Osp::Ui::Controls::ScrollPanel *__pScrollPanel;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	void MessageAppControlEmailSample(void);
};

#endif	//_FORMDETAILS_H_
