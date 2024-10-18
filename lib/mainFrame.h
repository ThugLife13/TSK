#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/spinctrl.h>

class mainFrame : public wxFrame {
public:
    mainFrame(const wxString &title);
    ~mainFrame();
private:
    void startButtonHandler(wxCommandEvent& evn);
    void newWindowCheckBoxHandler(wxCommandEvent& env);
    void radarPosXSliderHandler(wxCommandEvent& env);
    void radarPosYSliderHandler(wxCommandEvent& env);
    void carSpeedControllerHandler(wxCommandEvent& env);
};



#endif //MAINFRAME_H
