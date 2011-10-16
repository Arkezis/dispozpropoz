/*
 * SearchForm.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#ifndef SEARCHFORM_H_
#define SEARCHFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

using namespace Osp::Graphics;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

class SearchForm  :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::ITouchEventListener {

public:
	SearchForm();
	virtual ~SearchForm();
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
	static const int ID_SEARCHBAR = 101;
	static const int ID_CHECKBUTTON_1 = 201;
	static const int ID_CHECKBUTTON_2 = 202;
	static const int ID_CHECKBUTTON_3 = 203;
	static const int ID_CHECKBUTTON_4 = 204;
	static const int ID_CHECKBUTTON_5 = 205;
	static const int ID_CHECKBUTTON_6 = 206;
	static const int ID_BUTTON_SEARCH = 301;
	static const int ID_FOOTERITEM1 = 401;
	static const int ID_HEADER_ABOUT_BUTTON = 501;


	Osp::Ui::Controls::SearchBar *pSearchBar;
	Osp::Ui::Controls::CheckButton *pCheckButton1;
	Osp::Ui::Controls::CheckButton *pCheckButton2;
	Osp::Ui::Controls::CheckButton *pCheckButton3;
	Osp::Ui::Controls::CheckButton *pCheckButton4;
	Osp::Ui::Controls::CheckButton *pCheckButton5;
	Osp::Ui::Controls::CheckButton *pCheckButton6;
	Integer categorySelected;
	String textEntered;

	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
};

#endif /* SEARCHFORM_H_ */
