#include <iostream>
#include <graphics.h>

#define square 0
#define circle 1

#define X 0
#define Y 0

#define EMPTY_FIGURE_NAME 0
#define EMPTY_STRING 1
#define EXPECTED_OPENED_BRACKET 2
#define INVALID_SYMBOL 3
#define EXPECTED_FLOAT_TYPE 4
#define EXPECTED_SPACE 5
#define EXPECTED_COMMA 6
#define EXPECTED_CLOSED_BRACKET 7


using namespace std;

void errorLog(int string, int symbol, int errorCode);

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

main()
{
	cout << "Start sucess\n";

	char  input[500];  // up to 500 symbols while not dynamic
	char* strings[15]; // up to 15  strings while not dynamic
	int  i = 0,
		 j = 0,
		 k = 0;
	int  difNum;
	int  stringsNum = 1;
	
	FILE* file;
    file = fopen("figures.txt", "r");

    do {
		input[i] = fgetc(file);
		if (input[i] == '\n') 
		{	
			input[i] = '\0';
			stringsNum += 1;
			strings[j++] = input + i + 1;
		}
	}
    while (input[i++] != EOF);
	input[--i] = '\0';
	
	int const figuresNum = 2;

	int    inputCode[15];
	float* inputData[15];

	char figuresNames[][8] = {
		"square",
		"circle",
	};
	int  figuresDatas[]    = {
		3, // X, Y, a
		3, // X, Y, r
	};
	int  figuresCodes[]    = {
		square,
		circle,
	};

	char* inputPtr = input;
	int string = 0;


	// i - string index
	// j - symbol index
	// k - figure index, Data index later
	for (i = 0; i < stringsNum; i += 1)
	{
		cout << strings[i] << '\n';

		if (strings[i][0] == '(') {errorLog(i, j, EMPTY_FIGURE_NAME); continue;}
		if (strings[i][0] == '\0') {errorLog(i, j, EMPTY_STRING); continue;}

		j = -1;


		while (isalpha(strings[i][++j]));
		
		if (isdigit(strings[i][j])) {errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] == ')') {errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] != '(') {errorLog(i, j, INVALID_SYMBOL); continue;}


		for (k = 0; k < figuresNum; k += 1)
			if (stringsCompare(inputPtr, figuresNames[k], '(')) break;

		inputCode[i] = k;
		inputData[i] = new float[figuresDatas[k]];


		int dataNum = figuresDatas[k];

		for (int cord = 0; cord < 2; cord += 1)
		{
			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') {errorLog(i, j, EXPECTED_FLOAT_TYPE); continue;}
			if (strings[i][j] != '.') {errorLog(i, j, INVALID_SYMBOL); continue;}


			while (isdigit(strings[i][++j]));

			if (cord == 0)
			{
				if (strings[i][j] == ',') {errorLog(i, j, EXPECTED_SPACE); continue;}
				if (strings[i][j] != ' ') {errorLog(i, j, INVALID_SYMBOL); continue;}
			}
		}

		for(k = 0; k < dataNum; k += 1)
		{
			if (strings[i][j] == ' ' || strings[i][j] == '.') {errorLog(i, j, EXPECTED_COMMA); continue;}
			if (strings[i][j] != ',') {errorLog(i, j, INVALID_SYMBOL); continue;}
			if (isdigit(strings[i][++j])) {errorLog(i, j, EXPECTED_SPACE); continue;}
			if (strings[i][j] != ' ') {errorLog(i, j, INVALID_SYMBOL); continue;}

			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') {errorLog(i, j, EXPECTED_FLOAT_TYPE); continue;}
			if (strings[i][j] != '.') {errorLog(i, j, INVALID_SYMBOL); continue;}


			while (isdigit(strings[i][++j]));
		}

		if (strings[i][j] != ')') {errorLog(i, j, EXPECTED_CLOSED_BRACKET); continue;}
	}

	while (inputPtr[1] != '\0')
	{
		int  datas = figuresDatas[i];
		int  afterPointSymbols;
		bool wasPoint;

		for (; inputPtr[-1] != '('; inputPtr += 1);

		for (i = 0; i < datas; i += 1)
		{
			wasPoint = false;
			afterPointSymbols = 0;
			inputData[string][i] = 0;

			for (; inputPtr[0] != ',' && inputPtr[0] != ')'; inputPtr += 1)
			{
				if (inputPtr[0] == '.') 
				{                                    
					wasPoint = true; 
					continue;
				}
				
				if (wasPoint) afterPointSymbols += 1;
				inputData[string][i] +  digitFromChar(inputPtr[0]);
				inputData[string][i] *= 10;
			}
			inputPtr += 2;
		}
		inputPtr -= 2;

		string += 1;
	}
	
	
	int windowHeight = 1200;
	int windowWidth  = 1600;
	
	int fps = 60;
}