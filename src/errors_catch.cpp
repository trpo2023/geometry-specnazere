#include <iostream>

#include "errors_catch.h"

#define EMPTY_FIGURE_NAME 0
#define EMPTY_STRING 1
#define EXPECTED_OPENED_BRACKET 2
#define INVALID_SYMBOL 3
#define EXPECTED_FLOAT_TYPE 4
#define EXPECTED_SPACE 5
#define EXPECTED_COMMA 6
#define EXPECTED_CLOSED_BRACKET 7
#define EXPECTED_STRING_END 8
#define INVALID_FIGURE 9

using namespace std;

void errorLog(int string, int symbol, int errorCode)
{
	for (int i = 0; i < symbol; i += 1) cout << ' ';
	cout << '^' << '\n';
	cout << "line " << string + 1 << ", col " << symbol + 1 << ':';
	
	switch(errorCode)
	{
		case EMPTY_FIGURE_NAME: cout << " Figure's name must have at least 1 english symbol"; break;
		case EMPTY_STRING: cout << " Empty line"; break;
		case EXPECTED_OPENED_BRACKET: cout << " After figure's name data must be in brackets"; break;
		case INVALID_SYMBOL: cout << " Unexpected symbol"; break;
		case EXPECTED_FLOAT_TYPE: cout << " there was no point, but requre float type"; break;
		case EXPECTED_SPACE: cout << " After comma must be space"; break;
		case EXPECTED_COMMA: cout << " Must be comma among datas"; break;
		case EXPECTED_CLOSED_BRACKET: cout << " Brackets must be closed"; break;
		case EXPECTED_STRING_END: cout << " After brackets line must end"; break;
		case INVALID_FIGURE: cout << " Figure's name don't match any supported"; break;
	}
	cout << '\n' << '\n';
}