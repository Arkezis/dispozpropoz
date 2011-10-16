/*
 * InfoForm.cpp
 *
 *  Created on: 16 Oct 2011
 *      Author: vj
 */

#include "InfoForm.h"

InfoForm::InfoForm() {
	// TODO Auto-generated constructor stub

}

InfoForm::~InfoForm() {
	// TODO Auto-generated destructor stub
}


bool
InfoForm::Initialize()
{
	// Construct an XML form
	Construct(L"INFO_FORM");

	return true;
}

result
InfoForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	/*Osp::Media::Image imgPlus;
	imgPlus.Construct();
	String imgPlusPath = L"/Home/plus_40.png";
	Bitmap *bitmapPlus = imgPlus.DecodeN(imgPlusPath, BITMAP_PIXEL_FORMAT_ARGB8888, 41, 41);

	Osp::Media::Image imgContact;
		imgPlus.Construct();
		String imgPlusPath = L"/Home/plus_40.png";
		Bitmap *bitmapPlus = imgPlus.DecodeN(imgPlusPath, BITMAP_PIXEL_FORMAT_ARGB8888, 41, 41);
	*/

	// Adds a ScrollPanel to the Form
	//AddControl(pScrollPanel);


	//Header and Footer

	Footer* pFooter = GetFooter();
	if(pFooter)
	{
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetBackButton();
		SetFormBackEventListener(this);
	}

	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Profil");

		ButtonItem buttonItem;
		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_ABOUT_BUTTON);
		AppResource* pAppResource = Osp::App::Application::GetInstance()->GetAppResource();
		Bitmap* __pBitmap = null;

		//TODO: use another icon instead of this
		if (pAppResource)
			__pBitmap = pAppResource->GetBitmapN(L"info.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
		pHeader->SetButton(BUTTON_POSITION_RIGHT, buttonItem);
		pHeader->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0x87,0xCD,0x4F));
		pHeader->AddActionEventListener(*this);
	}


	// Creates a ScrollPanel
	ScrollPanel* pScrollPanel = new ScrollPanel();
	pScrollPanel->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height));
	pScrollPanel->SetBackgroundColor(Color(0xF2, 0xE7, 0xE4));


	//Mes Infos
	// Creates a Panel
	Panel* pPanelInfos = new Panel();
	pPanelInfos->Construct(Rectangle(5, 5, GetClientAreaBounds().width-15, 200));
	pPanelInfos->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelInfos);

	Label* pLabelTitleInfos = new Label();
	pLabelTitleInfos->Construct(Rectangle(5, 5, 500, 30), "Mes Infos");
	pLabelTitleInfos->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleInfos->SetTextConfig(23, LABEL_TEXT_STYLE_ITALIC);
	pLabelTitleInfos->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleInfos);

	Label* pLabelPseudoTitle= new Label();
	pLabelPseudoTitle->Construct(Rectangle(5, 65, 500, 35), "Pseudo:");
	pLabelPseudoTitle->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelPseudoTitle->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelPseudoTitle->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelPseudoTitle);

	Label* pLabelPseudoValue= new Label();
	pLabelPseudoValue->Construct(Rectangle(100, 65, 500, 35), "Dindonpoilu");
	pLabelPseudoValue->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelPseudoValue->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelPseudoValue->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelPseudoValue);

	Label* pLabelEmailTitle= new Label();
	pLabelEmailTitle->Construct(Rectangle(5, 105, 500, 35), "Mail:");
	pLabelEmailTitle->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelEmailTitle->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelEmailTitle->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelEmailTitle);

	Label* pLabelEmailValue= new Label();
	pLabelEmailValue->Construct(Rectangle(100, 105, 500, 35), "dindonpoilu@bemyapp.com");
	pLabelEmailValue->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelEmailValue->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelEmailValue->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelEmailValue);

	Label* pLabelPhoneTitle= new Label();
	pLabelPhoneTitle->Construct(Rectangle(5, 145, 500, 35), "Phone:");
	pLabelPhoneTitle->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelPhoneTitle->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelPhoneTitle->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelPhoneTitle);

	Label* pLabelPhoneValue= new Label();
	//pLabelPhoneValue->Construct(Rectangle(100, 145, 500, 35), "06 12 34 56 78");
	pLabelPhoneValue->Construct(Rectangle(100, 145, 500, 35), "Masqué (privé)");
	pLabelPhoneValue->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelPhoneValue->SetTextConfig(30, LABEL_TEXT_STYLE_ITALIC);
	pLabelPhoneValue->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelPhoneValue);


	//Mes Dispoz
	// Creates a Panel
	Panel* pPanelMesDispoz= new Panel();
	pPanelMesDispoz->Construct(Rectangle(5, 215, GetClientAreaBounds().width-15, 500));
	pPanelMesDispoz->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelMesDispoz);

	Label* pLabelTitleMesDispoz = new Label();
	pLabelTitleMesDispoz ->Construct(Rectangle(5, 210, 500, 30), "Mes Dispoz");
	pLabelTitleMesDispoz ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleMesDispoz ->SetTextConfig(23, LABEL_TEXT_STYLE_ITALIC);
	pLabelTitleMesDispoz ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleMesDispoz );

	Label* pLabelDispo1Date = new Label();
	pLabelDispo1Date ->Construct(Rectangle(5, 245, 500, 35), "15 Oct 2011");
	pLabelDispo1Date ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo1Date ->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo1Date ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo1Date);

	Label* pLabelDispo1Rating = new Label();
	pLabelDispo1Rating ->Construct(Rectangle(305, 245, 500, 35), "*****");
	pLabelDispo1Rating ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo1Rating ->SetTextConfig(50, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo1Rating ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo1Rating );

	Label* pLabelDispo1Item = new Label();
	//pLabelPhoneValue->Construct(Rectangle(100, 145, 500, 35), "06 12 34 56 78");
	pLabelDispo1Item ->Construct(Rectangle(25, 280, 500, 35), "Machine à café");
	pLabelDispo1Item ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo1Item ->SetTextConfig(30, LABEL_TEXT_STYLE_ITALIC);
	pLabelDispo1Item ->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelDispo1Item);

	Label* pLabelDispo2Date = new Label();
	pLabelDispo2Date ->Construct(Rectangle(5, 325, 500, 35), "14 Oct 2011");
	pLabelDispo2Date ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo2Date ->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo2Date ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo2Date);

	Label* pLabelDispo2Rating = new Label();
	pLabelDispo2Rating ->Construct(Rectangle(305, 325, 500, 35), "****");
	pLabelDispo2Rating ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo2Rating ->SetTextConfig(50, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo2Rating ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo2Rating );

	Label* pLabelDispo2Item = new Label();
	pLabelDispo2Item ->Construct(Rectangle(25, 360, 500, 35), "Assiettes en carton");
	pLabelDispo2Item ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo2Item ->SetTextConfig(30, LABEL_TEXT_STYLE_ITALIC);
	pLabelDispo2Item ->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelDispo2Item);

	Label* pLabelDispo3Date = new Label();
	pLabelDispo3Date ->Construct(Rectangle(5, 405, 500, 35), "12 Oct 2011");
	pLabelDispo3Date ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo3Date ->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo3Date ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo3Date);

	Label* pLabelDispo3Rating = new Label();
	pLabelDispo3Rating ->Construct(Rectangle(305, 405, 500, 35), "*****");
	pLabelDispo3Rating ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo3Rating ->SetTextConfig(50, LABEL_TEXT_STYLE_NORMAL);
	pLabelDispo3Rating ->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelDispo3Rating );

	Label* pLabelDispo3Item = new Label();
	pLabelDispo3Item ->Construct(Rectangle(25, 440, 500, 35), "Casserole");
	pLabelDispo3Item ->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelDispo3Item ->SetTextConfig(30, LABEL_TEXT_STYLE_ITALIC);
	pLabelDispo3Item ->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelDispo3Item);

	// Adds a ScrollPanel to the Form
	AddControl(*pScrollPanel);

	return r;
}


void
InfoForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_HEADER_ABOUT_BUTTON:
	{
		//msgBoxAbout.Construct("About","Blah blah blah",MSGBOX_STYLE_OK ,0);

		String ABOUT_STRING = "Cette application a été développée dans le cadre du week-end BeMyApp Bada avec le support de Samsung.\nSuivez nous sur Twitter et Facebook!\nEquipe de développement-\nPorteur d'idée: Emilie ROCHER \nDéveloppement: Cyril ALIX, Tom DUBIN, Mathieu Cilheo, Romain PICHARD, Sathish VJ\nDesign: Sophie BAI, Marine GIRARD";
		msgBoxAbout.Construct("About",ABOUT_STRING,MSGBOX_STYLE_OK ,0);
		int modalResult = 0;
		msgBoxAbout.ShowAndWait(modalResult);
		break;
	}
	default:
		break;
	}

}

void
InfoForm::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	AppLog("Came here");
	Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));

	if(pFormMgr == null)
			return;
	Osp::Base::Collection::IList* args = new Osp::Base::Collection::LinkedList();
	args->Add(*(new String("")));
	args->Add(*(new String("-1")));
	pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, args);
}
