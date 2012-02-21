#ifndef _LED_WIDGET_HPP_
#define _LED_WIDGET_HPP_

#include <vector>

#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WStackedWidget>

class LedWidget : public Wt::WContainerWidget
{
   public:
      enum WIDGET_LED_STATE {WIDGET_LED_OFF, WIDGET_LED_GREEN, WIDGET_LED_YELLOW, WIDGET_LED_RED};

      LedWidget(Wt::WText *pLabel = NULL, Wt::Side labelSide = Wt::Bottom, Wt::WContainerWidget *parent = NULL);

      void setLed(WIDGET_LED_STATE led);
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

