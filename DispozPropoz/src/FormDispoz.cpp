#include "FormDispoz.h"
#include "FMedia.h";
#include "FormMgr.h"

//FApp.h

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

FormDispoz::FormDispoz(void)
{
}

FormDispoz::~FormDispoz(void)
{
}

bool
FormDispoz::Initialize()
{
	// Construct an XML form
	Construct(L"FormDispoz");

	return true;
}

result
FormDispoz::OnInitializing(void)
{
	result r = E_SUCCESS;
	this->items = new ArrayList();

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
	/*	FooterItem  footerItemCreate;
		footerItemCreate.Construct(ID_FOOTERITEM_MAP);
		footerItemCreate.SetText("Carte");
		pFooter->AddItem(footerItemCreate);*/
		FooterItem  footerItemCreate2;
		footerItemCreate2.Construct(ID_FOOTERITEM_PROPOZ);
		footerItemCreate2.SetText("Propoz'");
		pFooter->AddItem(footerItemCreate2);
		FooterItem  footerItemCreate3;
		footerItemCreate3.Construct(ID_FOOTERITEM_DISPOZ);
		footerItemCreate3.SetText("Dispoz'");
		pFooter->AddItem(footerItemCreate3);
		FooterItem  footerItemCreate4;
		footerItemCreate4.Construct(ID_FOOTERITEM_INFO);
		footerItemCreate4.SetText("Profil");
		pFooter->AddItem(footerItemCreate4);
		pFooter->AddActionEventListener(*this);
	}


	__pList = new ListView();
	__pList->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height-pFooter->GetHeight()), true, false);

	__pList->SetTextOfEmptyList(L"Chargement...");
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	__pList->SetItemDividerColor(Color(0xF7, 0xAE, 0x83));
	AddControl(*__pList);


	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Dispoz'");

		ButtonItem buttonItem;
		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_ABOUT_BUTTON);
		AppResource *pAppResource = Application::GetInstance()->GetAppResource();
		Bitmap* __pBitmap = null;

		//TODO: use another icon instead of this
		if (pAppResource)
			__pBitmap = pAppResource->GetBitmapN(L"info.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
		pHeader->SetButton(BUTTON_POSITION_RIGHT, buttonItem);
		pHeader->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0x87,0xCD,0x4F));
		pHeader->AddActionEventListener(*this);
	}

	return r;
}

void FormDispoz::populateWithParams(String* arg1, String* arg2){
	AppLog("I've got params !!");

	String add = "";
	if (arg2->CompareTo("-1")){
		add = "&category=";
		add.Append(arg2->GetPointer());
	}
	String* uri = new String("http://cilheo.fr/propoz.php?action=list&X=254&Y=32&range=2555");
	uri->Append(add);
	//uri->Append("&contains='");
//	uri->Append(arg1->GetPointer());
	//uri->Append("'");
	String host(L"http://cilheo.fr");

	AppLog("%ls",uri->GetPointer());

	__cjp = new CALJsonParser();
	__cjp->setJSONparserListener((Form*)this);
	__cjp->PerformJSON(host, *uri);
}

result
FormDispoz::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void FormDispoz::OnFormBackRequested(Osp::Ui::Controls::Form& source){

}

void
FormDispoz::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	/*	case ID_FOOTERITEM_MAP:
		{
			msgBoxMap.Construct("Carte des dispoz'","Cette fonctionnalité n'est pas disponible pour l'instant",MSGBOX_STYLE_OK ,0);
			int modalResult = 0;
			msgBoxMap.ShowAndWait(modalResult);
		}
		break;*/
		case ID_FOOTERITEM_PROPOZ:
		{
			Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
			FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
			if(pFormMgr == null)	return;
			pFormMgr->SendUserEvent(FormMgr::REQUEST_PROPOZ, null);
		}
		break;
		case ID_FOOTERITEM_DISPOZ:
		{
			Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
			FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
			if(pFormMgr == null)	return;
			pFormMgr->SendUserEvent(FormMgr::REQUEST_SEARCHDISPOZ, null);
		}
		break;
		case ID_FOOTERITEM_INFO:
		{
			Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
			FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));
			if(pFormMgr == null)	return;
			pFormMgr->SendUserEvent(FormMgr::REQUEST_PROFILE, null);
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
FormDispoz::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
{
	Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));

	if(pFormMgr == null)
			return;
	pFormMgr->SendUserEvent(FormMgr::REQUEST_DETAILSDISPOZ, null);
}

void
FormDispoz::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
    {
        	// Todo:
	AppLog("Coucou cheup2");

}

void
FormDispoz::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{
        	// Todo:
	AppLog("Coucou cheup3");

}

int
FormDispoz::GetItemCount(void)
{
	return this->items->GetCount();
}

Osp::Ui::Controls::ListItemBase*
FormDispoz::CreateItem(int index, int itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	Osp::Media::Image image;
	image.Construct();
	String titiPath = L"/Home/loupe_80.png";
	//AppResource* pouet = Application::GetInstance-GetAppResource()
	Bitmap *bitmapSearch = image.DecodeN(titiPath, BITMAP_PIXEL_FORMAT_ARGB8888, 79, 86);

	CustomItem* pItem = new CustomItem();

	Propoz* propoz = (Propoz*)this->items->GetAt(index);

	String titre = propoz->titre;
	titre.Append(" - ");
	titre.Append(propoz->nombres);
	titre.Append(propoz->volumes);

	style = LIST_ANNEX_STYLE_NORMAL;
	pItem->Construct(Osp::Graphics::Dimension(itemWidth,110), style);
	pItem->AddElement(Rectangle(5, 10, 200, 50), ID_LISTVIEW_TITLE, titre, 26, Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), true);
	pItem->AddElement(Rectangle(5, 40, 200, 50), ID_LISTVIEW_DESC, propoz->getCategory(), 26, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
	pItem->AddElement(Rectangle(270, 30, 200, 50), ID_LISTVIEW_DIST, propoz->range, 30, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
	pItem->AddElement(Rectangle(415, 35, 39, 46), ID_LISTVIEW_IMG, *bitmapSearch);
	pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0xDE, 0xC4, 0xBD));
	pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_PRESSED, Color(0xF5, 0xB4, 0xA2));
	pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_HIGHLIGHTED, Color(0xF5, 0xB4, 0xA2));
// ajouter un listener ?
	return pItem;
}

bool
FormDispoz::DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}


void
FormDispoz::onJSONparsingTerminated(){
	this->items = new ArrayList();
	this->__pList->UpdateList();
	this->__pList->RequestRedraw(true);
	ArrayList* aKey = __cjp->getKeyList();
	IList* aValue = __cjp->getValueList();

	int i=0;
	AppLog("nombre recu = %d",aKey->GetCount());
	while (i<aKey->GetCount()){

		String* value = ((String*)aValue->GetAt(i));

		if (value->CompareTo("Value is an Object")==0) {
			Propoz* b = new Propoz();

			b->construct(aKey->GetItemsN(i+1,9),aValue->GetItemsN(i+1,9));
			this->items->Add(*b);
		}
		i++;
	}
	this->__pList->UpdateList();
	this->__pList->RequestRedraw(true);
}


void
FormDispoz::OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 6");

}

void
FormDispoz::OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 4");

}

void
FormDispoz::OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 3");

}

void
FormDispoz::OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 2");

}

void
FormDispoz::OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 1");

}

void
FormDispoz::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	AppLog("Coucou cheup");

}

void
FormDispoz::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here
	 AppLog("Cheup 5");

}
