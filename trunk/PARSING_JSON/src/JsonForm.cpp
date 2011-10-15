#include "JsonForm.h"

using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Base::Runtime;
using namespace Osp::Base::Utility;
using namespace Osp::Base::Collection;
using namespace Osp::Io;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Web::Json;
using namespace Osp::Graphics;

JsonForm::JsonForm(void): __pList(null), __pLabel(null), __pValueList(null), __pJsonKeyList(null), __pButton(null)/*, __listIndex(0)*/
{
}

JsonForm::~JsonForm(void)
{
}

int isArray = 0;

bool
JsonForm::Initialize()
{
	Construct(FORM_STYLE_NORMAL | FORM_STYLE_HEADER | FORM_STYLE_FOOTER | FORM_STYLE_INDICATOR);
	return true;
}

result
JsonForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	Rectangle clientRect = GetClientAreaBounds();
	AppLog("%d, %d, %d, %d",clientRect.x, clientRect.y, clientRect.width, clientRect.height );
	Header* pHeader = GetHeader();
	pHeader->SetTitleText("JSON Parser");
	Footer* pFooter = GetFooter();
	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT );
	pFooter->AddActionEventListener(*this);

	FooterItem footerItem;
	footerItem.Construct(ACTION_PRESS);
	footerItem.SetText(L"START");

	pFooter->AddItem(footerItem);

	__pLabel = new Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 150, 380, 80), L"");
	AddControl(*__pLabel);

	__pList = new ListView();
	__pList->Construct(Rectangle(0, 0, 480, 400), true);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	__pList->SetTextOfEmptyList(L"");
	AddControl(*__pList);

	__pValueList = new LinkedList();

	__pJsonKeyList = new ArrayList();
	__pJsonKeyList->Construct();
	return r;
}

void
JsonForm::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
{
	String* pVal = static_cast<String*>(__pValueList->GetAt(index));
	if (pVal)
	{
		__pLabel->SetText(*pVal);
		__pLabel->RequestRedraw();
	}
}

void
JsonForm::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
{

}

void
JsonForm::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{

}

int
JsonForm::GetItemCount(void)
{
	if(__pJsonKeyList)
	{
		return __pJsonKeyList->GetCount();
	}
	return 0;
}

Osp::Ui::Controls::ListItemBase*
JsonForm::CreateItem(int index, int itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	SimpleItem* pItem = new SimpleItem();

	pItem->Construct(Osp::Graphics::Dimension(itemWidth,80), style);
	Osp::Base::String* key = static_cast<String*>(__pJsonKeyList->GetAt(index));
	pItem->SetElement(*key, NULL);
	return pItem;
}

bool
JsonForm::DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}


//Recursively traverse IJsonValue obtained by parser (using ParseN)
void
JsonForm::TraverseFunction( IJsonValue *pValue )
{
	if (!__pList)
		return;
	if( !pValue )
		return ;
	else
	{
		switch (pValue->GetType())
		{
			case JSON_TYPE_OBJECT:
				{
					JsonObject* pObject = static_cast<JsonObject*>(pValue);
					IMapEnumeratorT<const String*, IJsonValue*>*  pMapEnum = pObject->GetMapEnumeratorN();
					while( pMapEnum->MoveNext() == E_SUCCESS )
					{
						const String* key = null;
						IJsonValue* value = null;
						pMapEnum->GetKey( key );
						String *pListKey = new String(*key);
						__pJsonKeyList->Add(*pListKey);

						String *pStr = null;
						isArray = 0;
						pMapEnum->GetValue( value );
						if( value->GetType() == JSON_TYPE_OBJECT )
						{
							  pStr = new String("Value is an Object");
							__pValueList->Add(*pStr);
						}
						else if( value->GetType() == JSON_TYPE_ARRAY )
						{
							pStr = new String("Value is an Array");
							__pValueList->Add(*pStr);
						}
						TraverseFunction( value );
					}
					delete pMapEnum;
				}
				break;
            case JSON_TYPE_STRING:
				{
					JsonString* pVal = static_cast<JsonString*>(pValue);
					if (isArray == 0)
					{
					  String *pStr = new String(*pVal);
					  __pValueList->Add(*pStr);
					}
				}
				break;
            case JSON_TYPE_ARRAY:
				{
					JsonArray* pJsonArray = static_cast<JsonArray*>(pValue);
					pJsonArray->GetCount();
					IEnumeratorT<IJsonValue*>* pEnum = pJsonArray->GetEnumeratorN();
					while( pEnum->MoveNext() == E_SUCCESS )
					{
						IJsonValue* pValue = null;
						pEnum->GetCurrent( pValue );
						if ((pValue->GetType() == JSON_TYPE_STRING) || (pValue->GetType() == JSON_TYPE_NUMBER) || (pValue->GetType() == JSON_TYPE_BOOL) || (pValue->GetType() == JSON_TYPE_NULL))
							isArray = 1;
						TraverseFunction( pValue );
					}
					delete pEnum;
				}
				break;
            case JSON_TYPE_NUMBER:
				{
					JsonNumber* pVal = static_cast<JsonNumber*>(pValue);
					String* pStr = new String((pVal->ToString()));
					if (isArray == 0)
						__pValueList->Add(*pStr);
				}
				break;
            case JSON_TYPE_BOOL:
				{
					String* pStr = null;
					JsonBool* pVal = static_cast<JsonBool*>(pValue);
					if (*pVal == true)
						pStr = new String("true");
					else
						pStr = new String("false");
					if (isArray == 0)
						__pValueList->Add(*pStr);
				}
				break;						
            case JSON_TYPE_NULL:
				{
					String* pStr = null;
					pStr = new String("null");
					if (isArray == 0)
						__pValueList->Add(*pStr);
				}
				break;
            default:
				break;
		}
		__pList->UpdateList();
	}
}

void
JsonForm::OnFastScrollIndexSelected (Osp::Ui::Control &source, Osp::Base::String &index)
{

}

result
JsonForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	if(__pValueList != NULL)
	{
		__pValueList->RemoveAll( true );
		delete __pValueList;
		__pValueList = NULL;
	}
	if(__pJsonKeyList != NULL)
	{
		__pJsonKeyList->RemoveAll( true );
		delete __pJsonKeyList;
		__pJsonKeyList = NULL;
	}

	// TODO: Add your termination code here

	return r;
}

void
JsonForm::OnActionPerformed (const Osp::Ui::Control &source, int actionId)
{
	switch(actionId)
	{
		case ACTION_PRESS:
			{
				//Clear older values on label, if any
				__pLabel->SetText(L"");
				__pLabel->RequestRedraw();

				String host(L"http://cilheo.fr");
				String uri(L"http://cilheo.fr/propoz.php?action=list&X=254&Y=32&range=2555&contains=toto");

				if(!__pHttpClient ) __pHttpClient = new HttpClient();
				__pHttpClient->SetOnHTTPClientDone((Form*)this);

				__pHttpClient->goHttpGet(host, uri);

			}
			break;
	}
}

void
JsonForm::OnHTTPClientDone(){

	ByteBuffer* toParse = __pHttpClient->getResults();

	if(!toParse)
	{
		AppLog("couldnt parse");
		return;
	}

	//Call Json Parser
	IJsonValue* pJson = JsonParser::ParseN(*toParse);
	if (pJson == null)
	{
		__pLabel->SetText(L"CORRUPTED INPUT DATA");
		__pLabel->RequestRedraw();
		return;
	}
	else
	{
		AppLog("Before traverse %d", __pList->GetItemCount());
		__pJsonKeyList->RemoveAll( true );
		__pValueList->RemoveAll( true );
		TraverseFunction (pJson);
		AppLog("After traverse");

		//clean up allocated jsonValues
		JsonType type = pJson->GetType();
		if( type == JSON_TYPE_OBJECT )
		{
			JsonObject *pObject = static_cast<JsonObject*>(pJson);
			pObject->RemoveAll(true);
		}
		if( type == JSON_TYPE_ARRAY )
		{
			JsonArray *pArray = static_cast<JsonArray*>(pJson);
			pArray->RemoveAll(true);
		}
		delete pJson;
	}
	__pList->ScrollToItem(0);
	Draw();
	Show();
}


