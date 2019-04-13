#include "ButtonPanel.h"
#include "DemoFrame.h"

void ButtonPanel::reset_game()
{
	current_round=0;
	human_score=0;
	npc_score=0;
	tie_score=0;

	button_chosen_text->SetLabelText("");
    chooses->SetLabelText("");
    predicted->SetLabelText("");
    winner->SetLabelText("");
    human_wins->SetLabelText(int_to_wxString(human_score));
    npc_wins->SetLabelText(int_to_wxString(npc_score));
    tie_wins->SetLabelText(int_to_wxString(tie_score));
    round_num->SetLabelText("0 of "+int_to_wxString(total_rounds));
}
bool ButtonPanel::set_total_rounds(int rounds)
{
	if(rounds<1 || rounds>100)
	{
		return false;
	}
	else
	{
		total_rounds = rounds;
		round_num->SetLabelText("0 of "+int_to_wxString(total_rounds));
		return true;
	}
}
int ButtonPanel::get_total_rounds()
{
	int x = total_rounds;
	return x;
}

void ButtonPanel::init()
{
	current_round=0;
	human_score=0;
	npc_score=0;
	tie_score=0;
	total_rounds = 20;
	//ML.cleardatabase(); //ML should get smarted even when player restarts
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    //******************************The Round Panel****************
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round: ");
    round_text->SetFont(round_text->GetFont().Larger());
    round_text->SetFont(round_text->GetFont().Bold());
    round_num = new wxStaticText(round_panel, wxID_ANY, "0 of "+int_to_wxString(total_rounds));
    round_num->SetFont(round_panel->GetFont().Larger());
    round_sizer->Add(round_text, 0, wxALIGN_CENTER, 0);
    round_sizer->Add(round_num, 0, 0, 0);
    round_panel->SetSizer(round_sizer);

    //*****************************Display "Human"****************************
    wxPanel *display_human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *display_human_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *display_human = new wxStaticText(display_human_panel, wxID_ANY, "Human");
    display_human->SetFont(display_human->GetFont().Larger());
    display_human->SetFont(display_human->GetFont().Bold());
    display_human_sizer->Add(display_human, 0, wxALIGN_CENTER, 0);
    display_human_panel->SetSizer(display_human_sizer);

    //*************************The button panel*********************
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    //******************************The human choice panel********************
    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Human Chooses:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_CENTER, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    //*****************************Display "Computer"****************************
    wxPanel *display_predict_panel = new wxPanel(this, wxID_ANY);
    wxSizer *display_predict_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *display_computer = new wxStaticText(display_predict_panel, wxID_ANY, "Computer");
    display_computer->SetFont(display_computer->GetFont().Larger());
    display_computer->SetFont(display_computer->GetFont().Bold());
    display_predict_sizer->Add(display_computer, 0, wxALIGN_CENTER, 0);
    display_predict_panel->SetSizer(display_predict_sizer);

    //******************************The predicted human choice Panel*************************
    wxPanel *predict_panel = new wxPanel(this, wxID_ANY);
    wxSizer *predict_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *predicted_human_choice = new wxStaticText(predict_panel, wxID_ANY, "Predicted human choice: ");
    predicted = new wxStaticText(predict_panel, wxID_ANY, "");
    predicted->SetFont(predicted->GetFont().Larger());
    predict_sizer->Add(predicted_human_choice, 0, wxALIGN_CENTER, 0);
    predict_sizer->Add(predicted, 0, 0, 0);
    predict_panel->SetSizer(predict_sizer);

    //******************************The computer chooses Panel***************************
    wxPanel *choose_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choose_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *therefore_computer_chooses = new wxStaticText(choose_panel, wxID_ANY, "Therefore computer chooses: ");
    chooses = new wxStaticText(choose_panel, wxID_ANY, "");
    chooses->SetFont(chooses->GetFont().Larger());
    choose_sizer->Add(therefore_computer_chooses, 0, wxALIGN_CENTER, 0);
    choose_sizer->Add(chooses, 0, 0, 0);
    choose_panel->SetSizer(choose_sizer);

    //*****************************The Winner Panel********************************8
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *the_winner = new wxStaticText(winner_panel, wxID_ANY, "The winner: ");
    the_winner->SetFont(the_winner->GetFont().Larger());
    the_winner->SetFont(the_winner->GetFont().Bold());
    winner = new wxStaticText(winner_panel, wxID_ANY, "");
    winner->SetFont(winner->GetFont().Larger());
    winner_sizer->Add(the_winner, 0, wxALIGN_CENTER, 0);
    winner_sizer->Add(winner, 0, 0, 0);
    winner_panel->SetSizer(winner_sizer);

    //******************************The Statistics panel*****************
    wxPanel *statistics_panel = new wxPanel(this, wxID_ANY);
    wxSizer *statistics_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *statistics = new wxStaticText(statistics_panel, wxID_ANY, "Statistics");
    statistics->SetFont(statistics->GetFont().Larger());
    statistics->SetFont(statistics->GetFont().Bold());
    statistics_sizer->Add(statistics, 0, wxALIGN_CENTER, 0);
    statistics_panel->SetSizer(statistics_sizer);

    //*****************************The human score Panel********************************8
    wxPanel *humanscore_panel = new wxPanel(this, wxID_ANY);
    wxSizer *humanscore_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *humanscore = new wxStaticText(humanscore_panel, wxID_ANY, "Human wins: ");
    humanscore->SetFont(humanscore->GetFont().Larger());
    human_wins = new wxStaticText(humanscore_panel, wxID_ANY, "0");
    human_wins->SetFont(human_wins->GetFont().Larger());
    humanscore_sizer->Add(humanscore, 0, wxALIGN_CENTER, 0);
    humanscore_sizer->Add(human_wins, 0, 0, 0);
    humanscore_panel->SetSizer(humanscore_sizer);

    //*****************************The npc score Panel********************************8
    wxPanel *npcscore_panel = new wxPanel(this, wxID_ANY);
    wxSizer *npcscore_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *npcscore = new wxStaticText(npcscore_panel, wxID_ANY, "NPC wins: ");
    npcscore->SetFont(npcscore->GetFont().Larger());
    npc_wins = new wxStaticText(npcscore_panel, wxID_ANY, "0");
    npc_wins->SetFont(npc_wins->GetFont().Larger());
    npcscore_sizer->Add(npcscore, 0, wxALIGN_CENTER, 0);
    npcscore_sizer->Add(npc_wins, 0, 0, 0);
    npcscore_panel->SetSizer(npcscore_sizer);

    //*****************************The npc score Panel********************************8
    wxPanel *tiescore_panel = new wxPanel(this, wxID_ANY);
    wxSizer *tiescore_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *tiescore = new wxStaticText(tiescore_panel, wxID_ANY, "Tie: ");
    tiescore->SetFont(tiescore->GetFont().Larger());
    tie_wins = new wxStaticText(tiescore_panel, wxID_ANY, "0");
    tie_wins->SetFont(tie_wins->GetFont().Larger());
    tiescore_sizer->Add(tiescore, 0, wxALIGN_CENTER, 0);
    tiescore_sizer->Add(tie_wins, 0, 0, 0);
    tiescore_panel->SetSizer(tiescore_sizer);

    //*****************************Which Panel Goes first****************
    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(display_human_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(display_predict_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(predict_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(0);
    sizer->Add(choose_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(statistics_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(humanscore_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(0);
    sizer->Add(npcscore_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(0);
    sizer->Add(tiescore_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(100);

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    play_round(ROCK);
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
	play_round(PAPER);
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
	play_round(SCISSORS);
}

void ButtonPanel::play_round(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
    npc=ML.pick(choice_to_char(choice));
    human=choice_to_char(choice);
    chooses->SetLabelText(char_to_wxString(npc));
    predicted->SetLabelText(char_to_wxString(ML.prediction()));

    if (human_win(human, npc)) {winner->SetLabelText("Human Wins"); human_score++;}
    else
    {
    	if (tie(human, npc)) {winner->SetLabelText("Tie"); tie_score++;}
    	else {winner->SetLabelText("NPC Wins"); npc_score++;}
    }
    human_wins->SetLabelText(int_to_wxString(human_score));
    npc_wins->SetLabelText(int_to_wxString(npc_score));
    tie_wins->SetLabelText(int_to_wxString(tie_score));
    if (!tie(human, npc)){current_round++;}
    round_num->SetLabelText(int_to_wxString(current_round)+" of "+int_to_wxString(total_rounds));

    if (current_round >= total_rounds){
    	std::cout<<"end game"<<endl;
    	if (human_score > npc_score){
    		human_wins_game = true;
    	}
    	else {
    		human_wins_game = false;
    	}
    	//end game
    	wxString end_game_text;
    	if(human_wins_game)
    	{
    		end_game_text = "Congratulations!\nYou won the game!";
    	}
    	else
    	{
    		end_game_text = "You lost the game!\nBetter luck next time.";
    	}

    	//see dialogs.cpp line 849 for reference
    	 wxMessageDialog dialog(this,
    	                           end_game_text,
    	                           "Game Over",
    	                           wxCENTER | wxOK );

    	dialog.SetOKLabel("Play Again");//THIS MAY NOT WORK ON ALL PLATFORMS
    	switch ( dialog.ShowModal() )
    	    {
    	        case wxID_OK:
    	        	reset_game();
    	        	break;

    	        default:
    	            wxLogError(wxT("Unexpected wxMessageDialog return code!"));
    	    }
    }
}
