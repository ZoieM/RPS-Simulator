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
	case 'X': return "Unknown";
	}
}

wxString int_to_wxString(int num)
{
	return to_string(num);
}
