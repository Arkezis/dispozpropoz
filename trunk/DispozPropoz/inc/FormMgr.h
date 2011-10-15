#ifndef _FORMMGR_H_
#define _FORMMGR_H_

#include <FUi.h>
#include <FApp.h>

class FormMgr :
	public Osp::Ui::Controls::Form
{
public:
		FormMgr(void);
		~FormMgr(void);

public:
		bool Initialize();

protected:
		virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs);

public:
		static const RequestId REQUEST_LISTDISPOZ = 100;
		static const RequestId REQUEST_SEARCHDISPOZ = REQUEST_LISTDISPOZ+1;
		static const RequestId REQUEST_PROPOZ = REQUEST_SEARCHDISPOZ+1;
		static const RequestId REQUEST_PROFILE = REQUEST_PROPOZ+1;
		static const RequestId REQUEST_DETAILSDISPOZ= REQUEST_PROFILE+1;

private:
		Form *__prevForm;
};

#endif
