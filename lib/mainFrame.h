#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "eventHandlers.h"
#include "vehicle.h"


class mainFrame : public wxFrame {
public:
    mainFrame(const wxString &title);
    ~mainFrame();
    // eventHandlers *handlers = new eventHandlers(1,1,1,1,true);
private:
    int i = 0;
    eventHandlers handlers;
};



#endif //MAINFRAME_H
