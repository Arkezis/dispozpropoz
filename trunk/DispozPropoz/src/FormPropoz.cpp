#include "FormPropoz.h"
#include "FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;
using namespace Osp::Locations;
using namespace Osp::Locations::Services;

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

	Footer* pFooter = GetFooter();
	if(pFooter)
	{
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_DISABLED,Color(0xE5,0xCE,0xCB));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_HIGHLIGHTED,Color(0xE5,0xCE,0xCB));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_PRESSED,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_DISABLED,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_HIGHLIGHTED,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_PRESSED,Color(0xE5,0xCE,0xCB));
		FooterItem  footerItemCreate;
		footerItemCreate.Construct(ID_BUTTON_ADD);
		footerItemCreate.SetText("Ajouter");
		pFooter->AddItem(footerItemCreate);
		pFooter->SetBackButton();
		pFooter->AddActionEventListener(*this);
		SetFormBackEventListener(this);
	}

	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Propoz'");

		ButtonItem buttonItem;
		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_ABOUT_BUTTON);
		AppResource *pAppResource = Application::GetInstance()->GetAppResource();
		Bitmap* __pBitmap = null;

		if (pAppResource)
			__pBitmap = pAppResource->GetBitmapN(L"info.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
		pHeader->SetButton(BUTTON_POSITION_RIGHT, buttonItem);
		pHeader->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0x87,0xCD,0x4F));
		pHeader->AddActionEventListener(*this);
	}



		//Mapping des trucs a ecrire
		pName = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_PRODUCTNAME"));
		pQuantity = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_QUANTITY"));
		pUnit = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_UNIT"));
		pDate = static_cast<EditDate *>(GetControl(L"IDC_EDITDATE_PEREMPT"));
		//On met la date a aujourd'hui
        if(pDate!=null){
        	pDate->SetCurrentDate();
        	pDate->SetDay(pDate->GetDay()+1);
        }


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
		case ID_BUTTON_ADD:
		{

			String pn(pName->GetText());
			String pq(pQuantity->GetText());
			String pu(pUnit->GetText());
			DateTime dt(pDate->GetDate());
			String sdt(dt.ToString());

			AppLog("%ls, %ls, %ls, %ls", &pn, &pq, &pu, &sdt);

			DateTime date;
			Osp::System::SystemTime::GetCurrentTime(date);
			if(date.CompareTo(pDate->GetDate())>=0){
				//TODO mettre une popup si le mec met une date plus tot
				Osp::Ui::Controls::MessageBox* msgB = new MessageBox();
				msgB->Construct(L"Problème de date",L"Impossible de mettre une date antérieure à aujoud\'hui",MSGBOX_STYLE_OK  ,0);
				int modalR = 0;
				msgB->ShowAndWait(modalR);
				return;
			}

			if(pn.IsEmpty() || pq.IsEmpty() || pu.IsEmpty()){
				//TODO ajouter message box pour dire qu'il y a quelque chose de vide...
				Osp::Ui::Controls::MessageBox* msgB = new MessageBox();
				msgB->Construct(L"Champs vide",L"Tous les champs doivent être remplis",MSGBOX_STYLE_OK  ,0);
				int modalR = 0;
				msgB->ShowAndWait(modalR);
				return;
			}

			locProvider = new LocationProvider();
			// Construct the LocationProvider by using GPS and WPS (Wi-Fi Positioning System) as its locating mechanism
			locProvider->Construct(LOC_METHOD_HYBRID);
			// *this c'est le listener comme sur android
			//5 c'est le nombre de seconde entre deux location update successive
			//le false, on veut pas les info satelite, seulement les information long lat
			locProvider->RequestLocationUpdates(*this, 1, false);
			isSent=false;

		}
		break;

		case ID_HEADER_ABOUT_BUTTON:
		{
			//msgBoxAbout.Construct("About","Blah blah blah",MSGBOX_STYLE_OK ,0);
			String ABOUT_STRING = "Cette application a été développée dans le cadre du week-end BeMyApp Bada avec le support de Samsung.\nSuivez nous sur Twitter et Facebook!\nEquipe de développement-\nPorteur d'idée: Emilie ROCHER \nDéveloppement: Cyril ALIX, Tom DUBIN, Mathieu Cilheo, Romain PICHARD, Sathish VJ\nDesign: Sophie BAI, Marine GIRARD";
			msgBoxAbout.Construct("About",ABOUT_STRING,MSGBOX_STYLE_OK ,0);

			int modalResult = 0;
			msgBoxAbout.ShowAndWait(modalResult);
			break;
		}

	default:
		break;
	}
}


void
FormPropoz::OnLocationUpdated(Location& location){
	if(isSent==false && location.GetQualifiedCoordinates() != null)
	     {
		locProvider->CancelLocationUpdates();
				isSent=true;
	           const QualifiedCoordinates *q =
	                 location.GetQualifiedCoordinates();
	            // The lat and lon values
	            double longitude = q->GetLongitude();
	            double latitude = q->GetLatitude();

	            AppLog("%f, %f", longitude, latitude);

	            String pn(pName->GetText());
				String pq(pQuantity->GetText());
				String pu(pUnit->GetText());
				DateTime dt(pDate->GetDate());
				String sdt(dt.ToString());

				AppLog("%ls, %ls, %ls, %ls", &pn, &pq, &pu, &sdt);
				HttpClient* hc = new HttpClient();
				hc->SetOnHTTPClientDone(dynamic_cast<Form*>(this));
				String host(L"http://cilheo.fr/");
				String uri(L"http://cilheo.fr/propoz.php?action=insert&domaine=0&titre=");
				uri.Append(pn);
				uri.Append("&date=");
				uri.Append(dt.GetTime().GetTicks());
				uri.Append("&x=");
				uri.Append(0);
				uri.Append("&y=");
				uri.Append(0);
				uri.Append("&nombres=");
				uri.Append(pq);
				uri.Append("&volumes=");
				uri.Append(pu);

				AppLog("-----------------------------------%ls", &uri);

				hc->goHttpGet(host, uri);
	     }
}


void
FormPropoz::OnHTTPClientDone(){
	AppLog("Je back");
	Form* f;
	OnFormBackRequested(*f);

}
void
FormPropoz::OnProviderStateChanged(LocProviderState newState){
	//todo : nothing atm...
}

void FormPropoz::OnFormBackRequested(Osp::Ui::Controls::Form& source){
		AppLog("Je back");
		Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
		FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
		if(pFormMgr == null)
				return;
		Osp::Base::Collection::IList* args = new Osp::Base::Collection::LinkedList();
		args->Add(*(new String("")));
		args->Add(*(new String("-1")));
		pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, args);
}


