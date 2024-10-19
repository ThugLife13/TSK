#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

class mainFrame : public wxFrame {
public:
    mainFrame(const wxString &title);
    ~mainFrame();
private:
    void startButtonHandler(wxCommandEvent& evt);
    void newWindowCheckBoxHandler(wxCommandEvent& evt);
    void radarPosXSliderHandler(wxCommandEvent& evt);
    void radarPosYSliderHandler(wxCommandEvent& evt);
    void carSpeedControllerHandler(wxCommandEvent& evt);

    int i = 0;
};



#endif //MAINFRAME_H
