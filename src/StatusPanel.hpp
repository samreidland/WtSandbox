#ifndef _STATUS_PANEL_HPP_
#define _STATUS_PANEL_HPP_

#include <Wt/WContainerWidget>

#include "LedWidget.hpp"

class StatusPanel : public Wt::WContainerWidget
{
   public:
      StatusPanel(Wt::WContainerWidget *pParent);

   private:
      LedWidget   mAlarmMinor;
      LedWidget   mAlarmMajor;
      LedWidget   mAlarmCritical;
};

#endif

