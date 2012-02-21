#include <Wt/WPanel>
#include <Wt/WTable>
#include <Wt/WText>

#include "StatusPanel.hpp"

using namespace Wt;

StatusPanel::StatusPanel(WContainerWidget *pParent) :
   WContainerWidget(pParent)
{
   WPanel *pPanel = new WPanel(this);
   pPanel->setTitle("Status LEDs");
   

   WTable *pLedTable = new WTable();
   pLedTable->setMargin(WLength::Auto, Left | Right);
   mpAlarmMinor = new LedWidget(new WText("Minor"), Bottom);

   mpAlarmMajor = new LedWidget(new WText("Major"), Bottom);

   mpAlarmCritical = new LedWidget(new WText("Critical"), Bottom);

   pLedTable->elementAt(0, 0)->addWidget(mpAlarmMinor);
   pLedTable->elementAt(0, 1)->addWidget(mpAlarmMajor);
   pLedTable->elementAt(0, 2)->addWidget(mpAlarmCritical);

   pPanel->setCentralWidget(pLedTable);
   pPanel->setCollapsible(true);
}

void StatusPanel::setAlarmState(ALARM_STATE state)
{
   switch (state)
   {
   case OFF:
      mpAlarmMinor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmMajor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmCritical->setLed(LedWidget::WIDGET_LED_OFF);
      break;
   case MINOR:
      mpAlarmMinor->setLed(LedWidget::WIDGET_LED_YELLOW);
      mpAlarmMajor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmCritical->setLed(LedWidget::WIDGET_LED_OFF);
      break;
   case MAJOR:
      mpAlarmMinor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmMajor->setLed(LedWidget::WIDGET_LED_RED);
      mpAlarmCritical->setLed(LedWidget::WIDGET_LED_OFF);
      break;
   case CRITICAL:
      mpAlarmMinor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmMajor->setLed(LedWidget::WIDGET_LED_OFF);
      mpAlarmCritical->setLed(LedWidget::WIDGET_LED_RED);
      break;
   }
}
