#ifndef _FORMPROPOZ_H_
#define _FORMPROPOZ_H_

#include <FBase.h>
#include <FUi.h>
#include <FSysSystemTime.h>
#include "HttpClient.h"
#include <FLocations.h>

class FormPropoz :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public Osp::Ui::Controls::IFormBackEventListener,
	public Osp::Locations::ILocationListener,
	public HttpClient
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
	void OnLocationUpdated(Osp::Locations::Location& location);
	void OnProviderStateChanged(Osp::Locations::LocProviderState newState);
	void OnHTTPClientDone();
	static const int ID_HEADER_ABOUT_BUTTON = 501;
	Osp::Ui::Controls::MessageBox msgBoxAbout;

private:
	Osp::Ui::Controls::EditField* pName;
	Osp::Ui::Controls::EditField* pQuantity;
	Osp::Ui::Controls::EditField* pUnit;
	Osp::Ui::Controls::EditDate* pDate;
	bool isSent;
	Osp::Locations::LocationProvider *locProvider;

};

#endif	//_FORMPROPOZ_H_
