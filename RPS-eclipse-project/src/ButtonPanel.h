#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "ButtonDemo.h"
#include "Choice.h"
#include "SimpleMLPicker.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);

    void reset_game();

private:
    wxStaticText *button_chosen_text;
    wxStaticText *round_num;
    wxStaticText *predicted;
    wxStaticText *chooses;
    wxStaticText *winner;
    wxStaticText *human_wins;
    wxStaticText *npc_wins;
    wxStaticText *tie_wins;
    SimpleMLPicker ML;
    int num;
    int human_score;
    int npc_score;
    int tie_score;
    char human;
    char npc;

    /**
     * Initialize the panel contents.
     */
    void init();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_text (const Choice choice);
};

#endif /* BUTTONPANEL_H_ */
