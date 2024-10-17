#include "../lib/core.h"

bool core::OnInit() {
    mainFrame* MainFrame = new mainFrame("Doppler Radar");
    MainFrame->Center();
    MainFrame->Maximize(true);
    MainFrame->Show(true);
    SetTopWindow(MainFrame);
    return true;
}

core::core() {
}

core::~core() {
}