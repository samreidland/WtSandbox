#include <Wt/WPanel>
#include <Wt/WTable>

#include "StatusPanel.hpp"

using namespace Wt;

StatusPanel::StatusPanel(WContainerWidget *pParent) :
   WContainerWidget(pParent),
   mAlarmMinor(pParent),
   mAlarmMajor(pParent),
   mAlarmCritical(pParent)
{
   WPanel *pPanel = new WPanel();
   pPanel->setTitle("Status LEDs");
   

   WTable *pLedTable = new WTable();
   pLedTable->elementAt(0, 0)->addWidget(&mAlarmMinor);
   pLedTable->elementAt(0, 1)->addWidget(&mAlarmMajor);
   pLedTable->elementAt(0, 2)->addWidget(&mAlarmCritical);


   pPanel->setCentralWidget(pLedTable);

   addWidget(pPanel);

}
