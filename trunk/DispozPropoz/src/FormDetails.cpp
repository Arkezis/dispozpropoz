#include "FormDetails.h"
#include "FMedia.h";
#include "FormMgr.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;
using namespace Osp::Base::Collection;

FormDetails::FormDetails(void)
{
}

FormDetails::~FormDetails(void)
{
}

bool
FormDetails::Initialize()
{
	// Construct an XML form
	Construct(L"FormDetails");

	return true;
}

result
FormDetails::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	/*Osp::Media::Image imgPlus;
	imgPlus.Construct();
	String imgPlusPath = L"/Home/plus_40.png";
	Bitmap *bitmapPlus = imgPlus.DecodeN(imgPlusPath, BITMAP_PIXEL_FORMAT_ARGB8888, 41, 41);*/

//	Osp::Media::Image imgContact;
//	imgContact.Construct();
//	String imgContactPath = L"/Home/contact_198.png";
//Bitmap *bitmapContact = imgContact.DecodeN(imgContactPath, BITMAP_PIXEL_FORMAT_ARGB8888, 188, 44);

	Osp::Media::Image imgRating;
	imgRating.Construct();
	String imgRatingPath = L"/Home/star4.png";
	Bitmap *bitmapRating = imgRating.DecodeN(imgRatingPath, BITMAP_PIXEL_FORMAT_ARGB8888, 90, 86);

	Osp::Media::Image imgMap;
	imgMap.Construct();
	String imgMapPath = L"/Home/maps_IESA.png";
	Bitmap *bitmapMap = imgMap.DecodeN(imgMapPath, BITMAP_PIXEL_FORMAT_ARGB8888, 300, 218);

	// Adds a ScrollPanel to the Form
	//AddControl(pScrollPanel);

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
	pLabelTitleItem->Construct(Rectangle(5, 65, 350, 40), "John Karp");
	pLabelTitleItem->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleItem->SetTextColor(Color(0xE9, 0x50, 0x0E));
	pScrollPanel->AddControl(*pLabelTitleItem);

	Label* pLabelAdd1 = new Label();
	pLabelAdd1->Construct(Rectangle(5, 115, 350, 30), "IESA Multimedia");
	pLabelAdd1->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd1->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd1->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd1);

	Label* pLabelAdd2 = new Label();
	pLabelAdd2->Construct(Rectangle(5, 145, 350, 30), "étage 5");
	pLabelAdd2->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd2->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd2->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd2);

	Label* pLabelAdd3 = new Label();
	pLabelAdd3->Construct(Rectangle(5, 175, 350, 30), "5 avenue de l'Opéra");
	pLabelAdd3->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd3->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd3->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd3);

	Label* pLabelAdd4 = new Label();
	pLabelAdd4->Construct(Rectangle(5, 205, 350, 30), "75001 Paris");
	pLabelAdd4->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelAdd4->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelAdd4->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelAdd4);

	Label* pLabelImgRating = new Label();
	pLabelImgRating->Construct(Rectangle(300, 115, 90, 86), "");
	pLabelImgRating->SetBackgroundBitmap(*bitmapRating);
	//pLabelImgRating->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgRating);


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

	Label* pLabelTitleItemDispoz2 = new Label();
	pLabelTitleItemDispoz2->Construct(Rectangle(300, 335, 250, 40), "10 unités");
	pLabelTitleItemDispoz2->SetTextConfig(22, LABEL_TEXT_STYLE_NORMAL);
	pLabelTitleItemDispoz2->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTitleItemDispoz2->SetTextColor(Color(0x33, 0x33, 0x33));
	pScrollPanel->AddControl(*pLabelTitleItemDispoz2);

	//image +
/*	Label* pLabelImgPlus = new Label();
	pLabelImgPlus->Construct(Rectangle(405, 335, 41, 41), "");
	pLabelImgPlus->SetBackgroundBitmap(*bitmapPlus);
	//pLabelImgPlus->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgPlus);*/



	/* PANIER */
	// Creates a Panel
	Panel* pPanelPanier = new Panel();
	pPanelPanier->Construct(Rectangle(5, 395, GetClientAreaBounds().width-15, 300));
	pPanelPanier->SetBackgroundColor(Color(0xE5, 0xCE, 0xCB));
	pScrollPanel->AddControl(*pPanelPanier);

/*	Label* pLabelTitlePanier = new Label();
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
*/
	//image Maps
	Label* pLabelImgMap = new Label();
	pLabelImgMap->Construct(Rectangle(80, 420, 300, 218), "");
	pLabelImgMap->SetBackgroundBitmap(*bitmapMap);
	//pLabelImgMap->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgMap);
/*
	//image Contact
	Label* pLabelImgContact = new Label();
	pLabelImgContact->Construct(Rectangle(120, 675, 220, 60), "");
	pLabelImgContact->SetBackgroundBitmap(*bitmapContact);
	//pLabelImgContact->AddTouchEventListener();
	pScrollPanel->AddControl(*pLabelImgContact);

	//label image
	Label* pLabelTxt4Contact = new Label();
	pLabelTxt4Contact->Construct(Rectangle(180, 680, 188, 44), "Contacter");
	pLabelTxt4Contact->SetTextConfig(23, LABEL_TEXT_STYLE_NORMAL);
	pLabelTxt4Contact->SetTextHorizontalAlignment(ALIGNMENT_LEFT);
	pLabelTxt4Contact->SetTextColor(Color(0xFF, 0xFF, 0xFF));
	pScrollPanel->AddControl(*pLabelTxt4Contact);
*/
	//button Contacter

	//Button* pButton = new Button();
	//pButton->Construct(Rectangle(0, 0, 150, 80));
	//pScrollPanel->AddControl(*pButton);

	//EditField* pEdit = new EditField();
	//pEdit->Construct(Rectangle(0, 100, 150, 80));
	//pScrollPanel->AddControl(*pEdit);

	// Adds a ScrollPanel to the Form
	AddControl(*pScrollPanel);


	Footer* pFooter = GetFooter();
	if(pFooter)
	{
		FooterItem  footerItemCreate;
		footerItemCreate.Construct(ID_FOOTERITEM1);
		footerItemCreate.SetText("Contacter");
		pFooter->SetColor(Color(0xF2,0xE7,0xE4));
		pFooter->SetButtonColor(BUTTON_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->SetItemColor(FOOTER_ITEM_STATUS_NORMAL,Color(0xE5,0xCE,0xCB));
		pFooter->AddItem(footerItemCreate);
		pFooter->SetBackButton();
		pFooter->AddActionEventListener(*this);
		SetFormBackEventListener(this);
	}



	return r;
}

result
FormDetails::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}
void FormDetails::MessageAppControlEmailSample(void)
{
   result r = E_SUCCESS;
   ArrayList* pDataList = null;
   pDataList = new ArrayList();

   pDataList->Construct();
   String pData(L"subject: Message de PropozDispoz");
   pDataList->Add(pData);

   String pData2(L"text:");
   pDataList->Add(pData2);

   String pData3(L"to:alix.cyril@gmail.com");
   pDataList->Add(pData3);

   String pData4(L"cc:null");
   pDataList->Add(pData4);

   String pData5(L"bcc:null");
   pDataList->Add(pData5);

   String pData6(L"attachments:");
   pDataList->Add(pData6);

   AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_EMAIL,"");
   if(pAc)
   {
      r = pAc->Start(pDataList, null);
      if (r != E_SUCCESS) {
         AppLog("ERRO: %S",GetErrorMessage(r));
      }
      TryReturnVoid(r,GetErrorMessage(r));
      delete pAc;
   }
   pDataList->RemoveAll(true);
   delete pDataList;
}
void
FormDetails::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
//	switch(actionId)
//	{
//	case ID_FOOTERITEM1:
//		{
//			MessageAppControlEmailSample();
//		}
//		break;
//	default:
//		break;
//	}
}

 void OnFormBackRequested(Osp::Ui::Controls::Form& source){
	 Frame* pFrame = Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame();
	 	FormMgr* pFormMgr = dynamic_cast<FormMgr*> (pFrame->GetControl("FormMgr"));

	 	if(pFormMgr == null)
	 			return;
	 	Osp::Base::Collection::IList* args = new Osp::Base::Collection::LinkedList();
	 	args->Add(*(new String("")));
	 	args->Add(*(new String("-1")));
	 	pFormMgr->SendUserEvent(FormMgr::REQUEST_LISTDISPOZ, args);
 }
 void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){
 }
 void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {
 }
 void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){
 }
 void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){

 }
 void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){
 }
 void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){
 }
 void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo){
 }


