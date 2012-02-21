#include <Wt/WImage>
#include <Wt/WTable>
#include <Wt/WText>

#include "LedWidget.hpp"

using namespace Wt;

LedWidget::LedWidget(WText *pLabel, Side labelSide, WContainerWidget *parent) :
   WContainerWidget(parent),
   mLedOffImage("images/led_off.png"),
   mLedGreenImage("images/led_green.png"),
   mLedYellowImage("images/led_yellow.png"),
   mLedRedImage("images/led_red.png")
{
   //setStyleClass("led");
   mpLed = new WStackedWidget(this);
   mpLed->insertWidget(LED_OFF, &mLedOffImage);
   mpLed->insertWidget(LED_GREEN, &mLedGreenImage);
   mpLed->insertWidget(LED_YELLOW, &mLedYellowImage);
   mpLed->insertWidget(LED_RED, &mLedRedImage);

   mpLed->setCurrentIndex(LED_OFF);

   WTable *table = new WTable(this);

   if (pLabel != NULL)
   {
      switch (labelSide)
      {
         case Top:
            table->elementAt(0,0)->addWidget(pLabel);
            table->elementAt(1,0)->addWidget(mpLed);
            table->elementAt(0,0)->setContentAlignment(AlignCenter);
            break;
         case Bottom:
            table->elementAt(0,0)->addWidget(mpLed);
            table->elementAt(1,0)->addWidget(pLabel);
            table->elementAt(1,0)->setContentAlignment(AlignCenter);
            break;
         case Left:
            table->elementAt(0,0)->addWidget(pLabel);
            table->elementAt(0,1)->addWidget(mpLed);
            table->elementAt(0,0)->setContentAlignment(AlignMiddle);
            break;
         case Right:
            table->elementAt(0,0)->addWidget(mpLed);
            table->elementAt(0,1)->addWidget(pLabel);
            table->elementAt(0,1)->setContentAlignment(AlignMiddle);
            break;
         default:
            break;
      }
   }
}

void LedWidget::setLed(LED_STATE led)
{
   mpLed->setCurrentIndex(led);
}

void LedWidget::setLabel(const char *szText, Side side)
{
   if (mpLabel != NULL)
   {
      removeWidget(mpLabel);
      delete mpLabel;
   }
   mpLabel = new WText(szText);
   switch (side)
   {
      case Left:
         break;
      case Right:
         break;
      case Top:
         insertWidget(0, mpLabel);
         break;
      case Bottom:
         insertWidget(1, mpLabel);
         break;
      default:
         break;
   }
}

