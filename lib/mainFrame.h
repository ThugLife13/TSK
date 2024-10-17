#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

class mainFrame : public wxFrame {
public:
    mainFrame(const wxString &title);
    ~mainFrame();
};



#endif //MAINFRAME_H
