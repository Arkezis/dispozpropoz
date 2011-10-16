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
	Construct(L"IDF_FORM1");

	return true;
}

result
FormDispoz::OnInitializing(void)
{
	result r = E_SUCCESS;


	//Bitmap bitmap1;
	//Image* bitmapDecoder = new Image();
	//r=bitmapDecoder->Construct();
	//unsigned int col = 0xDEC4BD; //222, 196, 189
	// TODO: Add your initialization code here
	__pList = new ListView();
	__pList->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height /*- 200*/), true, false);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	__pList->SetItemDividerColor(Color(0xF7, 0xAE, 0x83));
	AddControl(*__pList);

	Footer* pFooter = GetFooter();
	if(pFooter)
	{
		AppLog("Cheupi a un petit sexe");
		FooterItem  footerItemCreate;
		footerItemCreate.Construct(ID_FOOTERITEM_MAP);
		footerItemCreate.SetText("Carte");
		FooterItem  footerItemCreate2;
		footerItemCreate2.Construct(ID_FOOTERITEM_PROPOZ);
		footerItemCreate2.SetText("Propoz'");
		FooterItem  footerItemCreate3;
		footerItemCreate3.Construct(ID_FOOTERITEM_DISPOZ);
		footerItemCreate3.SetText("Dispoz'");
		FooterItem  footerItemCreate4;
		footerItemCreate4.Construct(ID_FOOTERITEM_INFO);
		footerItemCreate4.SetText("Info");
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		//pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->AddItem(footerItemCreate);
		pFooter->SetBackButton();
		pFooter->AddActionEventListener(*this);
		//SetFormBackEventListener(this);
	}

	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Dispoz'");
	}

	return r;
}

result
FormDispoz::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
FormDispoz::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
		case ID_FOOTERITEM_MAP:
		{
			// kedal ?
		}
		break;
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
			// kedal ?
		}
		break;
		default:
			break;
	}

}



void
FormDispoz::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
{
	// Todo:
}

void
FormDispoz::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
    {
        	// Todo:
}

void
FormDispoz::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{
        	// Todo:
}

int
FormDispoz::GetItemCount(void)
{
	return 10;
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

	switch (index % 3)
	{
	case 0:
		style = LIST_ANNEX_STYLE_NORMAL;
		pItem->Construct(Osp::Graphics::Dimension(itemWidth,110), style);
		//pItem->AddElement(Rectangle(10, 25, 100, 50), ID_LISTVIEW_TITLE, L"Home", true);
		pItem->AddElement(Rectangle(5, 10, 200, 50), ID_LISTVIEW_TITLE, L"Dindonpoilu", 26, Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), true);
		pItem->AddElement(Rectangle(5, 40, 200, 50), ID_LISTVIEW_DESC, L"Oeufs - Frigo", 26, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		pItem->AddElement(Rectangle(270, 30, 200, 50), ID_LISTVIEW_DIST, L"-250m", 30, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		//AppResource * res = Application::GetAppResource::GetInstance()->GetAppResource();
		//Bitmap * pBitmap = res->GetBitmapN(L"loupe_80.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		pItem->AddElement(Rectangle(415, 35, 39, 46), ID_LISTVIEW_IMG, *bitmapSearch);
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0xDE, 0xC4, 0xBD));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_PRESSED, Color(0xF5, 0xB4, 0xA2));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_HIGHLIGHTED, Color(0xF5, 0xB4, 0xA2));
		break;
	case 1:
		style = LIST_ANNEX_STYLE_NORMAL;
		pItem->Construct(Osp::Graphics::Dimension(itemWidth,110), style);
		pItem->AddElement(Rectangle(5, 10, 200, 50), ID_LISTVIEW_TITLE, L"Dindonpoilu", 26,Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), true);
		pItem->AddElement(Rectangle(5, 40, 200, 50), ID_LISTVIEW_DESC, L"Oeufs - Frigo", 26, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		pItem->AddElement(Rectangle(270, 30, 200, 50), ID_LISTVIEW_DIST, L"-250m", 30, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		pItem->AddElement(Rectangle(415, 35, 39, 46), ID_LISTVIEW_IMG, *bitmapSearch);
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0xDE, 0xC4, 0xBD));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_PRESSED, Color(0xF5, 0xB4, 0xA2));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_HIGHLIGHTED, Color(0xF5, 0xB4, 0xA2));
		break;
	case 2:
		style = LIST_ANNEX_STYLE_NORMAL;
		pItem->Construct(Osp::Graphics::Dimension(itemWidth,110), style);
		pItem->AddElement(Rectangle(5, 10, 200, 50), ID_LISTVIEW_TITLE, L"Dindonpoilu", 26, Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), Color(0xE9, 0x50, 0x0E), true);
		pItem->AddElement(Rectangle(5, 40, 200, 50), ID_LISTVIEW_DESC, L"Oeufs - Frigo", 26, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		pItem->AddElement(Rectangle(270, 30, 200, 50), ID_LISTVIEW_DIST, L"-250m", 30, Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), Color(0x33, 0x33, 0x33), true);
		pItem->AddElement(Rectangle(415, 35, 39, 46), ID_LISTVIEW_IMG, *bitmapSearch);
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_NORMAL, Color(0xDE, 0xC4, 0xBD));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_PRESSED, Color(0xF5, 0xB4, 0xA2));
		pItem->SetBackgroundColor(LIST_ITEM_DRAWING_STATUS_HIGHLIGHTED, Color(0xF5, 0xB4, 0xA2));
		break;
	/*case 1:
		style = LIST_ANNEX_STYLE_MARK;
		pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
		//pItem->AddElement(Rectangle(10, 25, 100, 50), ID_LISTVIEW_TITLE, L"Msg", true);
		break;
	case 2:
		style = LIST_ANNEX_STYLE_ONOFF_SLIDING;
		pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
		//pItem->AddElement(Rectangle(10, 25, 100, 50), ID_LISTVIEW_TITLE, L"Alarm", true);
            break;*/
        default:
            break;
    }

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
FormDispoz::OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
FormDispoz::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}
