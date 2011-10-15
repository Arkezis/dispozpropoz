#include "HttpClient.h"
#include "JsonForm.h"
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Net::Http;

HttpClient::HttpClient():__content()
{
}


HttpClient::~HttpClient()
{
}

void
HttpClient::goHttpGet(String &hostAddr, String &uriAddr)
{
	result r = E_SUCCESS;
	HttpTransaction* pTransaction = null;
	HttpRequest* pRequest = null;

	if(__pSession == null)
	{
		AppLog("Session null!");
		__pSession = new HttpSession();
		AppLog("Session created!");
		if(__pSession == null)
			goto CATCH;
		
		r = __pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);
		if (IsFailed(r))
			goto CATCH;
	}

	pTransaction = __pSession->OpenTransactionN();
	if (null == pTransaction)
	{
		r = GetLastResult();
		goto CATCH;
	}

	r = pTransaction->AddHttpTransactionListener(*this);
	if (IsFailed(r))
		goto CATCH;

	pRequest = const_cast<HttpRequest*>(pTransaction->GetRequest());
	if(pRequest == null)
	{
		r = GetLastResult();
		goto CATCH;
	}

	r = pRequest->SetUri(uriAddr);
	if(IsFailed(r))
		goto CATCH;

	r = pRequest->SetMethod(NET_HTTP_METHOD_GET);
	if(IsFailed(r))
		goto CATCH;

	r = pTransaction->Submit();
	if(IsFailed(r))
		goto CATCH;

	return;

CATCH:
	if(pTransaction != null)
	{
		delete pTransaction;
		pTransaction = null;
	}
	AppLog("HttpClient::TestHttpGet() failed. (%s)", GetErrorMessage(r));
	return;
}


///////////////////////////////////////////////////////////
// IHttpTransactionEventListener
///////////////////////////////////////////////////////////

void HttpClient::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen)
{
	AppLog("####### OnTransactionReadyToRead! #######");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	if(pHttpResponse == null) return;

	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
	{
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if(pHttpHeader != null)
		{
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();

			__content = pHttpResponse->ReadBodyN();

//			int bufferLimit = pBuffer->GetLimit();
//
//			char rspData[bufferLimit+1];
//			pBuffer->SetPosition(0);
//			pBuffer->GetArray((byte*)rspData, 0, bufferLimit);
//			rspData[bufferLimit] ='\0';
//			__content->Clear();
//			__content->Append(rspData);

			delete tempHeaderString;

			((JsonForm*)__app)->OnHTTPClientDone();
//			delete pBuffer;
		}
	}
}

void
HttpClient::SetOnHTTPClientDone(Osp::Ui::Controls::Form* app){
	__app = app;
}


Osp::Base::ByteBuffer* HttpClient::getResults(){
	return __content;
}

void HttpClient::OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r)
{
	AppLog("####### OnTransactionAborted! (%s)#######", GetErrorMessage(r));

	delete &httpTransaction;
}

void HttpClient::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	AppLog("####### OnTransactionReadyToWrite! #######");
}

void HttpClient::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool rs)
{
	AppLog("####### OnTransactionHeaderCompleted! #######");
}



void HttpClient::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
{
	AppLog("####### OnTransactionCompleted! #######");

	delete &httpTransaction;
}

void HttpClient::OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Osp::Base::String* pCert)
{
	AppLog("####### OnTransactionCertVerificationRequiredN! #######");
}


