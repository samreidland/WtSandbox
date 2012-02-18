#include "LedWidget.hpp"

#include <Wt/WImage>

using namespace Wt;


LedWidget::LedWidget(Wt::WContainerWidget *parent) :
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
}

void LedWidget::setLed(LED_STATE led)
{
   mpLed->setCurrentIndex(led);
}

