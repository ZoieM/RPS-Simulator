#include "DemoFrame.h"

// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_New, DemoFrame::on_new)
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
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_New, "&New Game\tF1",    "Start a new game"); //appended
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF2",   "Show about dialog");


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
    wxMessageBox(wxString::Format(
                        "Put code here to start a new game."
                    ),
                    "New Game Placeholder",
                    wxOK | wxICON_INFORMATION,
                    this);
}
void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    	wxDialog *d = new AboutDialog(NULL, "About RPS-Simulator", wxSize(-1, -1));
        d->ShowModal();
        d->Destroy();
}
/*void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
//                    "This is a button demo\n"
//                    "built with %s\n"
//                    "and running under %s.",
//                    wxVERSION_STRING,
//                    wxGetOsDescription()


    				"                                    GAME INSTRUCTIONS                                    \n\n"

    				"RPS-Simulator allows one player (you) to play a game\n"
    				"of Rock Paper Scissors against a computer player.\n\n\n"


    				"Every game of RPS-Simulator will have one or more\n"
    		    	"rounds (20 rounds by default). At the beginning of\n"
    				"every round, you and the computer player will each\n"
    				"pick a hand: Rock, Paper, or Scissors. Then, both\n"
    				"hands will be revealed and compared to see who wins.\n\n\n"


    				"The rules to win a round of Rock Paper Scissors are\n"
    				"as follows:\n\n"

    					"\t- Rock crushes Scissors. \t(Rock wins against Scissors).\n"
    					"\t- Scissors cut Paper. 	\t(Scissors win against Paper).\n"
    					"\t- Paper covers Rock. 	\t(Paper wins against Rock).\n\n"

    				"But, if both players pick the same hand, they tie, so no\n"
    				"one will win the round.\n\n\n"


    				"After the winner of the round is revealed, the next\n"
    				"round will begin. After the last rounds, the player\n"
    				"who has won the most rounds will win the game."
                ),
                "About RPS-Simulator",
                wxOK | wxICON_INFORMATION,
                this);
}*/

void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

