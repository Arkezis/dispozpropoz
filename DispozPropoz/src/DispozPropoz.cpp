/**
 * Name        : DispozPropoz
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "DispozPropoz.h"
#include "FormMgr.h"
#include "Form1.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

DispozPropoz::DispozPropoz()
{
}

DispozPropoz::~DispozPropoz()
{
}

Application*
DispozPropoz::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new DispozPropoz();
}

bool
DispozPropoz::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);
/*
	// Create a form
	Form1 *pForm1 = new Form1();
	pForm1->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);

	// Set the current form
	pFrame->SetCurrentForm(*pForm1);

	// Draw and Show the form
	pForm1->Draw();
	pForm1->Show();

	return true;*/


	// WITH THE FORMMGR
	result r = E_SUCCESS;

	FormMgr *pFormMgr = new FormMgr();
	if(pFormMgr->Initialize())
	{
		// on ajoute à la frame le FormMgr
		r = Application::GetInstance()->GetAppFrame()->GetFrame()->AddControl(*pFormMgr);
		TryCatch(r == E_SUCCESS, , GetErrorMessage(r));
		// on définit le Form de départ et on ne donne pas de paramètres (on affiche tout)
		Osp::Base::Collection::IList* args = new Osp::Base::Collection::LinkedList();
		args->Add(*(new String("")));
		args->Add(*(new String("-1")));

		pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ,args);
	}
	return true;

	CATCH:
		SetLastResult(r);
		return false;
}

bool
DispozPropoz::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void
DispozPropoz::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
DispozPropoz::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
DispozPropoz::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
DispozPropoz::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
DispozPropoz::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
DispozPropoz::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
