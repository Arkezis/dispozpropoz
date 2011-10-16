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
		AppLog("Yes footer was created.");
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetBackButton();
		SetFormBackEventListener(this);
	}

	Header * pHeader = GetHeader();
	if(pHeader){
		pHeader->SetColor(Color(0x87,0xCD,0x4F));
		pHeader->SetTitleText(L"Dispoz'");

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


	/* INFOS */
	// Creates a Panel
	Panel* pPanelInfos = new Panel();
	pPanelInfos->Construct(Rectangle(5, 5, GetClientAreaBounds().width-15, 240));
	pPanelInfos->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelInfos);

	Label* pLabelTitleInfos = new Label();
	pLabelTitleInfos->Construct(Rectangle(5, 5, 400, 25), "Infos");
	pLabelTitleInfos->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleInfos->SetTextConfig(23, LABEL_TEXT_STYLE_ITALIC);
	pLabelTitleInfos->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleInfos);

	Label* pLabelTitleItem = new Label();
	pLabelTitleItem->Construct(Rectangle(5, 65, 350, 40), "Dindonpoilu");
	pLabelTitleItem->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleItem->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleItem);

	Label* pLabelAdd1 = new Label();
	pLabelAdd1->Construct(Rectangle(5, 115, 350, 30), "RÃ©sidence toto");
	pLabelAdd1->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd1->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd1->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd1);

	Label* pLabelAdd2 = new Label();
	pLabelAdd2->Construct(Rectangle(5, 145, 350, 30), "app 5 - Ã©tage 5");
	pLabelAdd2->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd2->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd2->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd2);

	Label* pLabelAdd3 = new Label();
	pLabelAdd3->Construct(Rectangle(5, 175, 350, 30), "5 avenue de l'OcÃ©an");
	pLabelAdd3->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd3->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd3->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd3);

	Label* pLabelAdd4 = new Label();
	pLabelAdd4->Construct(Rectangle(5, 205, 350, 30), "Le porge");
	pLabelAdd4->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd4->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd4->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd4);


	/* DISPOZ */
	// Creates a Panel
	Panel* pPanelDispoz = new Panel();
	pPanelDispoz->Construct(Rectangle(5, 250, GetClientAreaBounds().width-15, 140));
	pPanelDispoz->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelDispoz);

	Label* pLabelTitleDispoz = new Label();
	pLabelTitleDispoz->Construct(Rectangle(5, 270, 400, 25), "Dispoz'");
	pLabelTitleDispoz->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleDispoz->SetTextConfig(23, LABEL_TEXT_STYLE_ITALIC);
	pLabelTitleDispoz->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleDispoz);

	Label* pLabelTitleItemDispoz = new Label();
	pLabelTitleItemDispoz->Construct(Rectangle(5, 335, 330, 40), "Citron");
	pLabelTitleDispoz->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelTitleItemDispoz->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleItemDispoz->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelTitleItemDispoz);

	//image +
	Label* pLabelImgPlus = new Label();
	pLabelImgPlus->Construct(Rectangle(405, 335, 41, 41), "");
	//pLabelImgPlus->SetBackgroundBitmap(*bitmapPlus);
	//pLabelImgPlus->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgPlus);



	/* PANIER */
	// Creates a Panel
	Panel* pPanelPanier = new Panel();
	pPanelPanier->Construct(Rectangle(5, 395, GetClientAreaBounds().width-15, 170));
	pPanelPanier->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelPanier);

	Label* pLabelTitlePanier = new Label();
	pLabelTitlePanier->Construct(Rectangle(5, 400, 400, 25), "Panier");
	pLabelTitlePanier->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitlePanier->SetTextConfig(23, LABEL_TEXT_STYLE_ITALIC);
	pLabelTitlePanier->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitlePanier);

	Label* pLabelNumberItemsPanier = new Label();
	pLabelNumberItemsPanier->Construct(Rectangle(5, 430, 50, 40), "4");
	pLabelNumberItemsPanier->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelNumberItemsPanier->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelNumberItemsPanier);

	Label* pLabelTxt4NumberItemsPanier = new Label();
	pLabelTxt4NumberItemsPanier->Construct(Rectangle(55, 430, 330, 40), "article(s) dans le panier");
	pLabelTxt4NumberItemsPanier->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelTxt4NumberItemsPanier->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTxt4NumberItemsPanier->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelTxt4NumberItemsPanier);

	//image +
	Label* pLabelImgContact = new Label();
	pLabelImgContact->Construct(Rectangle(50, 335, 110, 30), "");
	//pLabelImgContact->SetBackgroundBitmap(*bitmapContact);
	//pLabelImgContact->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgContact);

	//button Contacter

	//Button* pButton = new Button();
	//pButton->Construct(Rectangle(0, 0, 150, 80));
	//pScrollPanel->AddControl(*pButton);

	//EditField* pEdit = new EditField();
	//pEdit->Construct(Rectangle(0, 100, 150, 80));
	//pScrollPanel->AddControl(*pEdit);

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
	Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
	FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));

	if(pFormMgr == null)
			return;
	pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, null);
}
