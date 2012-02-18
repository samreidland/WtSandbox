
#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WServer>

#include <stdio.h>

#include "StatusPanel.hpp"

class TestApp : public Wt::WApplication
{
   public:
      TestApp(const Wt::WEnvironment &env);
};

TestApp::TestApp(const Wt::WEnvironment &env) :
   Wt::WApplication(env)
{
   printf("app created\n");
   new StatusPanel(root());
   printf("added StatusPanel\n");
}

Wt::WApplication *createApp(const Wt::WEnvironment &env)
{
   return new TestApp(env);
}
int main(int argc, char **argv)
{
   return Wt::WRun(argc, argv, &createApp);
}

