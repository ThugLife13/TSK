#include "../lib/mainFrame.h"

mainFrame::mainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title, wxPoint(10,10), wxSize(1920, 1080)), handlers(1) {
    wxPanel *mainPanel = new wxPanel(this, wxID_ANY);

    //MAIN WINDOW
    //start sim button
    wxButton* startButton = new wxButton(mainPanel, wxID_ANY, wxT("Start Sim"),
                                         wxPoint(200, 350), wxSize(200, -1));

    //track in new window checkBox
    // wxCheckBox* newWindowCheckBox = new wxCheckBox(mainPanel, wxID_ANY, wxT("Track sim in new window"),
    //                                                wxPoint(200, 250), wxSize(250, -1));

    //radar position controller
    wxSlider* radarPosXSlider = new wxSlider(mainPanel, wxID_ANY, 0, 0, 100,
                                             wxPoint(300, 60), wxSize(200, -1), wxSL_VALUE_LABEL);
    wxSlider* radarPosYSlider = new wxSlider(mainPanel, wxID_ANY, 0, 0, 100,
                                             wxPoint(300, 100), wxSize(200, -1), wxSL_VALUE_LABEL);

    //speed controller
    wxSpinCtrl* carSpeedControllerHandler = new wxSpinCtrl(mainPanel, wxID_ANY, wxT("1"),
                                                     wxPoint(300, 160), wxSize(200, -1), wxSP_WRAP, 1, 320);
    //static text
    wxStaticText* radarPosXText = new wxStaticText(mainPanel, wxID_ANY, wxT("Radar Position X (0-100)   [% width]"),
                                                wxPoint(50, 80), wxSize(200, -1));
    wxStaticText* radarPosYText = new wxStaticText(mainPanel, wxID_ANY, wxT("Radar Position Y (0-100)   [% height]"),
                                                wxPoint(50, 120), wxSize(200, -1));
    wxStaticText* carSpeedText = new wxStaticText(mainPanel, wxID_ANY, wxT("Car true speed    (1-100)   [km/h]"),
                                                wxPoint(50, 160), wxSize(200, -1));

    //showing track
    wxImage::AddHandler(new wxPNGHandler());
    wxImage::AddHandler(new wxJPEGHandler());

    wxStaticBitmap* mapBitmap = new wxStaticBitmap(mainPanel, wxID_ANY, wxBitmap(wxT("../tmp/map.png"), wxBITMAP_TYPE_PNG),
                                                   wxPoint(600, 20), wxSize(-1, -1));

    wxStaticBitmap* radarBitmap = new wxStaticBitmap(mapBitmap, wxID_ANY, wxBitmap(wxT("../tmp/radar.png"), wxBITMAP_TYPE_PNG),
                                                     wxPoint(0, 0), wxSize(-1, -1));

    //radar movement
    radarPosXSlider->Bind(wxEVT_SLIDER, [radarBitmap, mapBitmap, this](wxCommandEvent& event) {
        int xPosPercentage = event.GetInt();

        std::cout << xPosPercentage << std::endl;

        int mapWidth = mapBitmap->GetSize().GetWidth() - radarBitmap->GetSize().GetWidth();
        int newXPos = (mapWidth * xPosPercentage) / 100;
        int yPos = radarBitmap->GetPosition().y;
        radarBitmap->SetPosition(wxPoint(newXPos, yPos));

        std::cout << radarBitmap->GetPosition().x+(radarBitmap->GetSize().x/2) << std::endl; //to do zmiennej
        handlers.radarPositionX = radarBitmap->GetPosition().x+(radarBitmap->GetSize().x/2);

        radarBitmap->Refresh();
    });
    radarPosYSlider->Bind(wxEVT_SLIDER, [radarBitmap, mapBitmap, this](wxCommandEvent& event) {
        int yPosPercentage = event.GetInt();

        std::cout << yPosPercentage << std::endl;

        int mapHeight = mapBitmap->GetSize().GetHeight() - radarBitmap->GetSize().GetHeight();
        int newYPos = (mapHeight * yPosPercentage) / 100;
        int xPos = radarBitmap->GetPosition().x;
        radarBitmap->SetPosition(wxPoint(xPos, newYPos));

        std::cout << radarBitmap->GetPosition().y+(radarBitmap->GetSize().y/2) << std::endl; //to do zmiennej
        handlers.radarPositionY = radarBitmap->GetPosition().y+(radarBitmap->GetSize().y/2);

        radarBitmap->Refresh();
    });

    //handlers
    startButton->Bind(wxEVT_BUTTON, &eventHandlers::startButtonHandler, &handlers);
    //newWindowCheckBox->Bind(wxEVT_CHECKBOX, &eventHandlers::newWindowCheckBoxHandler, &handlers);
    carSpeedControllerHandler->Bind(wxEVT_SPINCTRL, &eventHandlers::carSpeedControllerHandler, &handlers);

    CreateStatusBar();
}

mainFrame::~mainFrame() {
}
