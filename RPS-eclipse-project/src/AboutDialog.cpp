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
	SetSizer(m_itemBoxSizer);

	//___SUBTITLE TEXT
	wxStaticText *subtitle = new wxStaticText(this, wxID_ANY, wxT("GAME INSTRUCTIONS"), wxPoint(-1, -1), wxSize(-1,-1), wxALIGN_CENTRE_HORIZONTAL);
	//BEGIN Make subtitle bold
	wxFont font = subtitle->GetFont();
	font.SetWeight(wxFONTWEIGHT_BOLD);
	font.SetSymbolicSize(wxFONTSIZE_LARGE);
	subtitle->SetFont(font);
	//END

	//___BODY TEXT
	wxStaticText *body = new wxStaticText(this, wxID_ANY, wxT("RPS-Simulator allows one player (you) to play a game\n"
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
			"whoever has won the most rounds will win the game."
	    ), wxPoint(-1, -1), wxSize(-1,-1), wxALIGN_LEFT);

// wxEXPAND makes no difference
m_itemBoxSizer->Add(subtitle, 1, wxEXPAND, 10);	//add subtitle text to sizer
m_itemBoxSizer->Add(body, 1, wxALIGN_TOP, 10); 		//add body text to sizer
m_itemBoxSizer->InsertSpacer(1,7);								//add a blank spacer inbetween both text
Show(this);
m_itemBoxSizer->SetMinSize(GetSize());

}
