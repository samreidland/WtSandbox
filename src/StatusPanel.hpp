#ifndef _STATUS_PANEL_HPP_
#define _STATUS_PANEL_HPP_

#include <Wt/WContainerWidget>

#include "LedWidget.hpp"

enum ALARM_STATE {OFF, MINOR, MAJOR, CRITICAL};

class StatusPanel : public Wt::WContainerWidget
{
   public:
      StatusPanel(Wt::WContainerWidget *pParent = NULL);

      void setAlarmState(ALARM_STATE state);
   private:
      LedWidget   *mpAlarmMinor;
      LedWidget   *mpAlarmMajor;
      LedWidget   *mpAlarmCritical;
};

#endif

