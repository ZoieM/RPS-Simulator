#ifndef CHOICE_H_
#define CHOICE_H_

#include "wx/wx.h"
#include <string>
using namespace std;

// Choice represented by int.
typedef int Choice;

// Which object a player chooses each round.
enum { ROCK, PAPER, SCISSORS, NONE };

/**
 * Convert a chosen object to a wxString.
 * @param choice the object to convert.
 * @return the wxString.
 */
wxString choice_to_wxString(Choice choice);
wxString int_to_wxString(int num);

#endif /* CHOICE_H_ */
