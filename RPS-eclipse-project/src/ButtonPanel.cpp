#include "ButtonPanel.h"

void ButtonPanel::init()
{
	num=0;
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

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

    //******************************The Round Panel****************
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round: ");
    round_num = new wxStaticText(round_panel, wxID_ANY, "");
    round_num->SetFont(round_panel->GetFont().Larger());
    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    round_sizer->Add(round_num, 0, 0, 0);
    round_panel->SetSizer(round_sizer);

    //******************************The Text panel********************
    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Human Chooses:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    //*****************************Which Panel Goes first****************
    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    update_button_choice_text(ROCK);
    update_round_num();
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    update_button_choice_text(PAPER);
    update_round_num();
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(SCISSORS);
    update_round_num();
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_round_num (void)
{
	num++;
	round_num->SetLabelText(int_to_wxString(num));
}
