#ifndef DEMOFRAME_H_
#define DEMOFRAME_H_

#include "ButtonPanel.h"
#include "AboutDialog.h"
/**
 * The application frame.
 */
class DemoFrame : public wxFrame
{
public:
    /**
     * Constructor.
     * @param title the window title.
     */
    DemoFrame(const wxString& title);

    /**
     * Destructor.
     */
    virtual ~DemoFrame();

    /**
     * Event handler for the New Game menu item.
     * @param event the item selection event.
     */
    void on_new(wxCommandEvent& event);

    /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
    void on_about(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);

    //Prompt the total_rounds per game from user
    void on_rounds(wxCommandEvent& event);

    void prompt_total_rounds();

private:
    // The event table that maps events to their handlers.
    wxDECLARE_EVENT_TABLE();

    ButtonPanel *button_panel;

    /**
     * Initialize the contents of the application frame.
     */
    void init();

    /**
     * Initialize the application frame's menu and status bars.
     */
    void init_menu_bar();

    /**
     * Initialize the application frame's sizer.
     */
    void init_sizer();
};

// IDs for the menu commands.
enum
{
    RPS_Quit  = wxID_EXIT,
    RPS_About = wxID_ABOUT,
	RPS_Rounds = wxID_PROPERTIES,
	RPS_New   = wxID_NEW //appended
};

#endif /* DEMOFRAME_H_ */
