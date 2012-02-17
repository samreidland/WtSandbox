#ifndef _LED_WIDGET_HPP_
#define _LED_WIDGET_HPP_

#include <vector>

#include <Wt/WContainerWidget>


enum LED_STATE {LED_OFF, LED_GREEN, LED_YELLOW, LED_RED};

class LedWidget : public Wt::WContainerWidget
{
   public:

      LedWidget(Wt::WContainerWidget *parent = NULL);
      ~LedWidget();

      void setLed(LED_STATE led);

   private:
      std::vector<Wt::WImage *> mImages;
      LED_STATE mnImage;

      Wt::WImage *getImage(int index) const;
};

#endif

