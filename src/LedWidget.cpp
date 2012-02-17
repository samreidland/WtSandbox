#include "LedWidget.hpp"

#include <Wt/WImage>

using namespace Wt;


LedWidget::LedWidget(Wt::WContainerWidget *parent) :
   WContainerWidget(parent)
{
   //setStyleClass("led");
   WImage *image;

   image = new WImage("images/led_off.png", this);
   mImages.push_back(image);
   image->hide();

   image = new WImage("images/led_green.png", this);
   mImages.push_back(image);
   image->hide();

   image = new WImage("images/led_red.png", this);
   mImages.push_back(image);
   image->hide();

   image = new WImage("images/led_yellow.png", this);
   mImages.push_back(image);
   image->hide();

   mnImage = LED_OFF;
   setLed(mnImage);

}

LedWidget::~LedWidget()
{
}

void LedWidget::setLed(LED_STATE led)
{
   getImage(mnImage)->hide();
   mnImage = led;
   getImage(mnImage)->show();
}

WImage *LedWidget::getImage(int index) const
{
   return mImages[index];
}
