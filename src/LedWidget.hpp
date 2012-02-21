#ifndef _LED_WIDGET_HPP_
#define _LED_WIDGET_HPP_

#include <vector>

#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WStackedWidget>


enum LED_STATE {LED_OFF, LED_GREEN, LED_YELLOW, LED_RED};

class LedWidget : public Wt::WContainerWidget
{
   public:

      LedWidget(Wt::WText *pLabel = NULL, Wt::Side labelSide = Wt::Bottom, Wt::WContainerWidget *parent = NULL);

      void setLed(LED_STATE led);
      void setLabel(const char *szText, Wt::Side side);

   private:
      Wt::WImage           mLedOffImage;
      Wt::WImage           mLedGreenImage;
      Wt::WImage           mLedYellowImage;
      Wt::WImage           mLedRedImage;
      Wt::WStackedWidget   *mpLed;
      Wt::WText            *mpLabel;
};

#endif

