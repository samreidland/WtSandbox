#include <Wt/WPanel>
#include <Wt/WTable>

#include "StatusPanel.hpp"

using namespace Wt;

StatusPanel::StatusPanel(WContainerWidget *pParent) :
   WContainerWidget(pParent)
{
   WPanel *pPanel = new WPanel(this);
   pPanel->setTitle("Status LEDs");
   

   WTable *pLedTable = new WTable();
   mpAlarmMinor = new LedWidget();
   mpAlarmMajor = new LedWidget();
   mpAlarmCritical = new LedWidget();
   pLedTable->elementAt(0, 0)->addWidget(mpAlarmMinor);
   pLedTable->elementAt(0, 1)->addWidget(mpAlarmMajor);
   pLedTable->elementAt(0, 2)->addWidget(mpAlarmCritical);


   pPanel->setCentralWidget(pLedTable);


}

void StatusPanel::setAlarmState(ALARM_STATE state)
{
   switch (state)
   {
   case OFF:
      mpAlarmMinor->setLed(LED_OFF);
      mpAlarmMajor->setLed(LED_OFF);
      mpAlarmCritical->setLed(LED_OFF);
      break;
   case MINOR:
      mpAlarmMinor->setLed(LED_RED);
      mpAlarmMajor->setLed(LED_OFF);
      mpAlarmCritical->setLed(LED_OFF);
      break;
   case MAJOR:
      mpAlarmMinor->setLed(LED_OFF);
      mpAlarmMajor->setLed(LED_RED);
      mpAlarmCritical->setLed(LED_OFF);
      break;
   case CRITICAL:
      mpAlarmMinor->setLed(LED_OFF);
      mpAlarmMajor->setLed(LED_OFF);
      mpAlarmCritical->setLed(LED_RED);
      break;
   }
}
