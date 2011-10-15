#ifndef _JSONFORM_H_
#define _JSONFORM_H_

#include <FBase.h>
#include <FApp.h>
#include <FSystem.h>
#include <FIo.h>
#include <FUi.h>
#include <FWebJson.h>
#include "HttpClient.h"
using namespace Osp::Web::Json;

class CALJsonParser :
	public HttpClient
{

// Construction
public:
	CALJsonParser(void);
	virtual ~CALJsonParser(void);

// Implementation
protected:
	HttpClient* __pHttpClient;
	Osp::Base::Collection::IList *__pValueList;
	Osp::Base::Collection::ArrayList* __pJsonKeyList;

public:
	virtual int GetItemCount(void);
	void PerformJSON (Osp::Base::String& host, Osp::Base::String& uri);
	//listener de HTTPclient done
	void OnHTTPClientDone();

	Osp::Base::Collection::IList * getValueList();
	Osp::Base::Collection::ArrayList* getKeyList();

	//Le jsonparseurlistener
	void setJSONparserListener(Osp::Ui::Controls::Form* f);
	virtual void onJSONparsingTerminated();

private:
	void TraverseFunction( IJsonValue *pValue );
	Osp::Ui::Controls::Form* __pForm;
};

#endif	//_JsonForm_H_
