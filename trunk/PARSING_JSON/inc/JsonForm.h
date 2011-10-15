#ifndef _JSONFORM_H_
#define _JSONFORM_H_

#include <FBase.h>
#include <FSystem.h>
#include <FIo.h>
#include <FUi.h>
#include <FWebJson.h>
#include "HttpClient.h"
using namespace Osp::Web::Json;

class JsonForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IListViewItemEventListener,
	public Osp::Ui::Controls::IListViewItemProvider,
	public Osp::Ui::Controls::IFastScrollListener,
	public Osp::Ui::IActionEventListener,
	public HttpClient
{

// Construction
public:
	static const int ACTION_PRESS  = 101;
	static const int ID_FORMAT_STRING = 102;
	JsonForm(void);
	virtual ~JsonForm(void);
	bool Initialize(void);
	void TraverseFunction( IJsonValue *pValue );

// Implementation
protected:
	HttpClient* __pHttpClient;
	Osp::Ui::Controls::ListView *__pList;
	Osp::Ui::Controls::Label *__pLabel;
	Osp::Base::Collection::IList *__pValueList;
	Osp::Base::Collection::ArrayList* __pJsonKeyList;
	Osp::Ui::Controls::Button *__pButton;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	//IActionEventListener
	virtual void OnActionPerformed(const Osp::Ui::Control &source, int actionId);

	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction);

	//IListViewItemProvider
	virtual Osp::Ui::Controls::ListItemBase* CreateItem (int index, int itemWidth);
	virtual bool  DeleteItem (int index, Osp::Ui::Controls::ListItemBase *pItem, int itemWidth);
	virtual int GetItemCount(void);

	//IFastScrollListener
	virtual void  OnFastScrollIndexSelected (Osp::Ui::Control &source, Osp::Base::String &index);

	//listener de HTTPclient done
	void OnHTTPClientDone();

};

#endif	//_JsonForm_H_
