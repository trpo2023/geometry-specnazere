#include <iostream>

using namespace std;

bool isDigit(char digit)
{
	switch (digit)
	{
		case '0': return 1;
		case '1': return 1;
		case '2': return 1;
		case '3': return 1;
		case '4': return 1;
		case '5': return 1;
		case '6': return 1;
		case '7': return 1;
		case '8': return 1;
		case '9': return 1;
		default : return 0;
	}
}

bool stringsCompare(char* string, char* etalonString, char stopSymbol = '\0')
{
	int dif = 0;
	int len  = 0;
	int etalonLen = 0;
	int lenDif;

	while (
		string[len] != '\0' &&
		string[len] != stopSymbol
	)   
		len += 1;

	while (
		etalonString[etalonLen] != '\0' &&
		etalonString[etalonLen] != stopSymbol
	)   
		etalonLen += 1;

	if (len != etalonLen) return 0;

	for (int i = 0; i < len; i += 1)
	{
		if (string[i] != etalonString[i]) return 0;
	}
	return 1;
}

int digitFromChar(char digit)
{
	switch (digit)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default : return -1;
	}
}