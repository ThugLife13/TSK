#include "../lib/mainFrame.h"

mainFrame::mainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title, wxPoint(10,10), wxSize(1920, 1080)) {
    wxPanel *mainPanel = new wxPanel(this, wxID_ANY);

    //MAIN WINDOW
    //start sim button
    wxButton* startButton = new wxButton(mainPanel, wxID_ANY, wxT("Start Sim"), wxPoint(100, 100), wxSize(100, -1));

    //track in new window checkBox
    wxCheckBox* newWindowCheckBox = new wxCheckBox(mainPanel, wxID_ANY, wxT("Track sim in new window"), wxPoint(100, 200), wxSize(100, -1));

    //radar position controller
    wxSlider* radarPosXSlider = new wxSlider(mainPanel, wxID_ANY, 10, 1, 100, wxPoint(100, 500), wxSize(100, -1));
    wxSlider* radarPosYSlider = new wxSlider(mainPanel, wxID_ANY, 10, 1, 100, wxPoint(100, 600), wxSize(100, -1));

    //speed controller
    wxSpinCtrl* speedSpinController = new wxSpinCtrl(mainPanel, wxID_ANY, wxT("Car true speed"), wxPoint(100, 700), wxSize(100, -1));


    //static text
    wxStaticText* firstText = new wxStaticText(mainPanel, wxID_ANY, wxT("First text - static"), wxPoint(100, 300), wxSize(100, -1));

    //handlers
    startButton->Bind(wxEVT_BUTTON, &mainFrame::startButtonHandler, this);
    newWindowCheckBox->Bind(wxEVT_CHECKBOX, &mainFrame::newWindowCheckBoxHandler, this);
    radarPosXSlider->Bind(wxEVT_SLIDER, &mainFrame::radarPosXSliderHandler, this);
    radarPosYSlider->Bind(wxEVT_SLIDER, &mainFrame::radarPosYSliderHandler, this);
    speedSpinController->Bind(wxEVT_SPINCTRL, &mainFrame::carSpeedControllerHandler, this);

}

mainFrame::~mainFrame() {
}

void mainFrame::startButtonHandler(wxCommandEvent& evn) {
    wxMessageBox("Button Clicked");
}

void mainFrame::newWindowCheckBoxHandler(wxCommandEvent& env) {
    wxMessageBox("CheckBox Clicked");

}

void mainFrame::radarPosXSliderHandler(wxCommandEvent& env) {
    //wxMessageBox("Slider X %d" + env.GetInt());

}

void mainFrame::radarPosYSliderHandler(wxCommandEvent& env) {
    //wxMessageBox("Slider Y %d" + env.GetInt());

}

void mainFrame::carSpeedControllerHandler(wxCommandEvent& env) {
    //wxMessageBox("Spin Controller X %d" + env.GetInt());

}

