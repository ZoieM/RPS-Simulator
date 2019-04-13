#include "DemoFrame.h"
#include "wx/numdlg.h"

// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_New, DemoFrame::on_new)
	EVT_MENU(RPS_Rounds, DemoFrame::on_rounds)
wxEND_EVENT_TABLE()

const int SIDE_MARGINS = 40;

DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      button_panel(new ButtonPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

DemoFrame::~DemoFrame()
{
    delete button_panel;
}

void DemoFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
    prompt_total_rounds();
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_New, "&New Game\tF1",    "Start a new game"); //appended
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF2",   "Show about dialog");
    helpMenu->Append(RPS_Rounds, "&Total Rounds\tF3",   "Change number of rounds");

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}

void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void DemoFrame::on_new(wxCommandEvent& WXUNUSED(event))
{
	button_panel->reset_game();
    /*wxMessageBox(wxString::Format(
                        "Put code here to start a new game."
                    ),
                    "New Game Placeholder",
                    wxOK | wxICON_INFORMATION,
                    this);*/

}
void DemoFrame::prompt_total_rounds()
{
	long desired_rounds = -1;
	wxString msg;
	int icon;

	while( desired_rounds < 1 || desired_rounds > 100)
	{
		desired_rounds = wxGetNumberFromUser(
			wxT("How many rounds do you want to play this game?\n"),
			wxT("Rounds:"),
			wxT("Welcome to RPS-Simulator"),
			static_cast<long>(button_panel->get_total_rounds()),
			1,
			100,
			this);

		if ( desired_rounds < 1 || desired_rounds > 100)//invalid num
		{
			msg = wxT("Invalid number of rounds.\nPlease enter a number between 1 and 100.");
			icon = wxICON_HAND;
		}
		else
		{
			int new_rounds = static_cast<int>(desired_rounds);
			button_panel->set_total_rounds(new_rounds);
			msg.Printf(wxT("The game will have %i rounds."), new_rounds );
			icon = wxICON_INFORMATION;
		}
		wxMessageBox(msg, wxT("Number of Rounds Per Game"), wxOK | icon, this);
	}
}
void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    	wxDialog *d = new AboutDialog(NULL, "About RPS-Simulator", wxSize(-1, -1));
        d->ShowModal();
        d->Destroy();
}
void DemoFrame::on_rounds(wxCommandEvent& WXUNUSED(event))
{
	this->prompt_total_rounds();
	button_panel->reset_game(); //don't let player change number of rounds in middle of game
}
void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

