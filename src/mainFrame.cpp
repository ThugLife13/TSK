#include "../lib/mainFrame.h"

mainFrame::mainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title, wxPoint(10,10), wxSize(1920, 1080)) {
    wxPanel *mainPanel = new wxPanel(this, wxID_ANY);
    wxButton* firstButton = new wxButton(mainPanel, wxID_ANY, wxT("First"), wxPoint(100, 100), wxSize(100, -1));

    wxCheckBox* firstCheck = new wxCheckBox(mainPanel, wxID_ANY, wxT("Check"), wxPoint(100, 200), wxSize(100, -1));

    wxStaticText* firstText = new wxStaticText(mainPanel, wxID_ANY, wxT("First text - static"), wxPoint(100, 300), wxSize(100, -1));

    wxTextCtrl* firstTextCtrl = new wxTextCtrl(mainPanel, wxID_ANY, wxT("First text"), wxPoint(100, 400), wxSize(100, -1));

    wxSlider* firstSlider = new wxSlider(mainPanel, wxID_ANY, 10, 1, 100, wxPoint(100, 500), wxSize(100, -1));

    wxSpinCtrl* firstSpin = new wxSpinCtrl(mainPanel, wxID_ANY, wxT("First number controller"), wxPoint(100, 600), wxSize(100, -1));
}

mainFrame::~mainFrame() {
}
