#include "ButtonPanel.h"

void ButtonPanel::init()
{
	num=0;
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    //******************************The Round Panel****************
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round: ");
    round_text->SetFont(round_text->GetFont().Larger());
    round_text->SetFont(round_text->GetFont().Bold());
    round_num = new wxStaticText(round_panel, wxID_ANY, "");
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
    sizer->AddSpacer(50);

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    update_text(ROCK);
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    update_text(PAPER);
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    update_text(SCISSORS);
}

void ButtonPanel::update_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
    chooses->SetLabelText(char_to_wxString(ML.pick(choice_to_char(choice))));
    predicted->SetLabelText(char_to_wxString(ML.prediction()));

    num++;
    round_num->SetLabelText(int_to_wxString(num));
}
