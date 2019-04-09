/*
 * AboutDialog.h
 *
 *  Created on: Apr 8, 2019
 *      Author: zoie
 */

#ifndef ABOUTDIALOG_H_
#define ABOUTDIALOG_H_

#include "wx/wx.h"

class AboutDialog: public wxDialog {
public:
    AboutDialog(wxWindow* parent, const wxString& aTitle, const wxSize aSize);

private:
    wxBoxSizer* m_itemBoxSizer;
    wxStaticText* m_text;
};

#endif /* ABOUTDIALOG_H_ */





