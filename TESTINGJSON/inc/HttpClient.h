#ifndef _HTTPCLIENT_H_
#define _HTTPCLIENT_H_


#include <FApp.h>
#include <FUi.h>
#include <FNet.h>
#include <FSystem.h>

class HttpClient : 
	public Osp::Net::Http::IHttpTransactionEventListener
	
{

public:
	HttpClient();
	~HttpClient();


public:
	///////////////////////////////////////////////////////////
	// IHttpTransactionEventListener
	///////////////////////////////////////////////////////////
	void OnTransactionReadyToRead(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	void OnTransactionAborted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, result r);
	void OnTransactionReadyToWrite(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	void OnTransactionHeaderCompleted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool rs);
	void OnTransactionCompleted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction);
	void OnTransactionCertVerificationRequiredN(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, Osp::Base::String* pCert);
	Osp::Base::ByteBuffer* getResults();
	void goHttpGet(Osp::Base::String &hostAddr, Osp::Base::String &uriAddr);

	//le listener a implementer
	virtual void OnHTTPClientDone();
	void SetOnHTTPClientDone(Object* parser);

private:
	Osp::Net::Http::HttpSession*	__pSession;
	Osp::Base::ByteBuffer* __content;
	Osp::Base::String* __httpHost;
	Osp::Base::String* __httpUri;
	Object* __parser;
};


#endif
