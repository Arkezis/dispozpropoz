#ifndef _FORMDISPOZ_H_
#define _FORMDISPOZ_H_

#include <FBase.h>
#include <FUi.h>
#include "CALJsonParser.h"
#include "Propoz.h"

using namespace Osp::Base::Collection;

class FormDispoz :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IListViewItemEventListener,
	public Osp::Ui::Controls::IListViewItemProvider,
 	public Osp::Ui::ITouchEventListener,
	public Osp::Ui::IActionEventListener,
	public CALJsonParser,
	public Osp::Ui::Controls::IFormBackEventListener

{

// Construction
public:
	FormDispoz(void);
	virtual ~FormDispoz(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_LISTVIEW_TITLE = 100;
	static const int ID_LISTVIEW_DESC = 101;
	static const int ID_LISTVIEW_DIST = 102;
	static const int ID_LISTVIEW_IMG = 103;
	static const int ID_FOOTERITEM_MAP= 201;
	static const int ID_FOOTERITEM_PROPOZ= ID_FOOTERITEM_MAP+1;
	static const int ID_FOOTERITEM_DISPOZ= ID_FOOTERITEM_PROPOZ+1;
	static const int ID_FOOTERITEM_INFO= ID_FOOTERITEM_DISPOZ+1;
	static const int ID_BUTTON_CLOSE_POPUP = 301;
	Osp::Ui::Controls::ListView* __pList;
	Osp::Ui::Controls::Popup* __pPopup;
	Osp::Ui::Controls::Popup* _pPopup;
	Osp::Ui::Controls::MessageBox msgBoxMap;

public:
		virtual result OnInitializing(void);
		virtual result OnTerminating(void);



		//JSonFinish
		void onJSONparsingTerminated();

		// IListViewItemEventListener
		virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
		virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status);
		virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction);

		//IListViewItemProvider
		virtual Osp::Ui::Controls::ListItemBase* CreateItem (int index, int itemWidth);
		virtual bool  DeleteItem (int index, Osp::Ui::Controls::ListItemBase *pItem, int itemWidth);
		virtual int GetItemCount(void);
		virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
		virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);


private:
	CALJsonParser* __cjp;
	ArrayList* items;
	Propoz a;
};

#endif	//_FORMDISPOZ_H_
