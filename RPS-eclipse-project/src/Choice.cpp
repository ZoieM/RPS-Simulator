#include "Choice.h"

wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "none";
    }
}

char choice_to_char (Choice choice)
{
	switch (choice)
	{
	case ROCK: return 'R';
	case PAPER: return 'P';
	case SCISSORS: return 'S';
	default: return 'I';
	}
}

wxString char_to_wxString(char choice)
{
	switch (choice)
	{
	case 'R': return "Rock";
	case 'P': return "Paper";
	case 'S': return "Scissors";
	default: return "Unknown";
	}
}

bool human_win (char human, char npc)
{
	if ((human=='R') && (npc=='S')) return true;
	else if ((human=='P') && (npc=='R')) return true;
	else if ((human=='S') && (npc=='P')) return true;
	else return false;
}

bool tie (char human, char npc)
{
	if (human==npc) return true;
	else return false;
}

wxString int_to_wxString(int num)
{
	return to_string(num);
}
