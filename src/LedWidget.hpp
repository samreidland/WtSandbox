#ifndef _LED_WIDGET_HPP_
#define _LED_WIDGET_HPP_

#include <vector>

#include <Wt/WContainerWidget>

#include "testserver.hpp"

typedef boost::signal<void (int)> LedSignal;

class LedWidget : public Wt::WContainerWidget
{
   public:
      LedWidget(LedSignal& sig, Wt::WContainerWidget *parent = NULL);
      ~LedWidget();

      void connect();

      void showLed(int led);

      void updateLed(int led);

   private:
      std::vector<Wt::WImage *> mImages;
      int mnImage;
      boost::signals::connection mConnection;
      Wt::WApplication *mpApp;

      Wt::WImage *getImage(int index) const;
};

#endif

