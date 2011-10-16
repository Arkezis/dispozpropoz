#include "CALJsonParser.h"

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

CALJsonParser::CALJsonParser(void): __pValueList(null), __pJsonKeyList(null)
{
	__pValueList = new LinkedList();
	__pJsonKeyList = new ArrayList();
	__pJsonKeyList->Construct();
}

CALJsonParser::~CALJsonParser(void)
{
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
}

int isArray = 0;

int
CALJsonParser::GetItemCount(void)
{
	if(__pJsonKeyList)
	{
		return __pJsonKeyList->GetCount();
	}
	return 0;
}

//Recursively traverse IJsonValue obtained by parser (using ParseN)
void
CALJsonParser::TraverseFunction( IJsonValue *pValue )
{
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
	}
}

//
//String host(L"http://cilheo.fr");
//String uri(L"http://cilheo.fr/propoz.php?action=list&X=254&Y=32&range=2555&contains=toto");
//
void
CALJsonParser::PerformJSON (String &host, String &uri)
{
	if(!__pHttpClient ) __pHttpClient = new HttpClient();
	__pHttpClient->SetOnHTTPClientDone((Object*)this);

	__pHttpClient->goHttpGet(host, uri);
}

void
CALJsonParser::OnHTTPClientDone(){

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
		return;
	}
	else
	{
		__pJsonKeyList->RemoveAll( true );
		__pValueList->RemoveAll( true );
		TraverseFunction (pJson);

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


		CALJsonParser* c = dynamic_cast<CALJsonParser*> (__pForm);


		c->onJSONparsingTerminated();
	}
}

void
CALJsonParser::setJSONparserListener(Osp::Ui::Controls::Form* form){
	__pForm = form;
}

IList *
CALJsonParser::getValueList(){
	return __pValueList;
}

ArrayList*
CALJsonParser::getKeyList(){
	return __pJsonKeyList;
}


