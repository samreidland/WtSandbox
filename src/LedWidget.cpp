#include "LedWidget.hpp"

#include <Wt/WImage>

using namespace Wt;


LedWidget::LedWidget(LedSignal& sig, Wt::WContainerWidget *parent) :
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

   mnImage = 0;
   showLed(mnImage);

   mConnection = sig.connect(boost::bind(&LedWidget::updateLed, this, _1));
   WApplication::instance()->enableUpdates();
   mpApp = WApplication::instance();
   printf("Application = %08x\n", mpApp);
}

LedWidget::~LedWidget()
{
   mConnection.disconnect();
}

void LedWidget::updateLed(int led)
{
   printf("updateLed %d\n", led);
   WApplication::UpdateLock lock(mpApp);
   if (lock)
   {
      printf("Got lock\n");
      showLed(led);

      mpApp->triggerUpdate();
   }
}

void LedWidget::showLed(int led)
{
   getImage(mnImage)->hide();
   mnImage = led;
   getImage(mnImage)->show();
}

WImage *LedWidget::getImage(int index) const
{
   printf("getImage %d\n", index);
   return mImages[index];
}
