/*
 * AboutDialog.cpp
 *
 *  Created on: Apr 8, 2019
 *      Author: zoie
 */

#include "AboutDialog.h"

AboutDialog::AboutDialog( wxWindow* parent, const wxString& aTitle, const wxSize aSize) :
wxDialog(parent, wxID_ANY, aTitle,
    wxPoint(-1, -1), aSize,
    wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	m_itemBoxSizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *subtitle_panel = new wxPanel(this, wxID_ANY);
    wxSizer *subtitle_sizer = new wxGridSizer(2, 0, 5);

    wxPanel *body_panel = new wxPanel(this, wxID_ANY);
    wxSizer *body_sizer = new wxGridSizer(2, 0, 5);

	//___SUBTITLE TEXT
	wxStaticText *subtitle = new wxStaticText(subtitle_panel, wxID_ANY, wxT("GAME INSTRUCTIONS"));
	//BEGIN Make subtitle bold and big
	subtitle->SetFont(subtitle->GetFont().Larger());
	subtitle->SetFont(subtitle->GetFont().Bold());
	//END

	//___BODY TEXT
	wxStaticText *body = new wxStaticText(body_panel, wxID_ANY, wxT(
			"RPS-Simulator allows one player (you) to play a game\n"
			"of Rock Paper Scissors against a computer player.\n\n"

			"Every game of RPS-Simulator will have one or more\n"
	    	"rounds (20 rounds by default). At the beginning of\n"
			"every round, you and the computer player will each\n"
			"pick a hand: Rock, Paper, or Scissors. Then, both\n"
			"hands will be revealed and compared to see who wins.\n\n"


			"The rules to win a round of Rock Paper Scissors are\n"
			"as follows:\n\n"

				"\t- Rock crushes Scissors. \t(Rock wins against Scissors).\n"
				"\t- Scissors cut Paper. 	\t(Scissors win against Paper).\n"
				"\t- Paper covers Rock. 	\t(Paper wins against Rock).\n\n"

			"But, if both players pick the same hand, they tie, so no\n"
			"one will win the round.\n"

			"After the winner of the round is revealed, the next\n"
			"round will begin. After the last rounds, the player\n"
			"whoever has won the most rounds will win the game."));

	subtitle_sizer->Add(subtitle, 0, wxALL, 0);
	subtitle_panel->SetSizer(subtitle_sizer);

	body_sizer->Add(body, 0, wxALL, 0);
	body_panel->SetSizer(body_sizer);

	m_itemBoxSizer->Add(subtitle_panel);
	m_itemBoxSizer->AddSpacer(10);
	m_itemBoxSizer->Add(body_panel);
	SetSizer(m_itemBoxSizer);
}
