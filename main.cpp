#include <iostream>

#include "src/errors_catch.h"
#include "src/strings.h"

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

#define polygon 0
#define circle  1

#define X 0
#define Y 0

int main()
{
	cout << "Start sucess\n";

	char  input[500];  // up to 500 symbols while not dynamic
	char* strings[15]; // up to 15  strings while not dynamic
	int  i = 0,
		 j = 1,
		 k = 0;
	//int  difNum;
	int  stringsNum = 1;
	
	FILE* file;
    file = fopen("figures.txt", "r");

	strings[0] = input;
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

	//int    inputCode[15];
	float* inputData[15];

	char figuresNames[][8] = {
		"polygon",
		"circle",
	};
	int  figuresDatas[]    = {
		0, // a
		1, // r
	};
	int  figuresCords[]    = {
		-1, // dynamic
		1,  // center
	};
	/*
	int  figuresCodes[]    = {
		square,
		circle,
	};*/

	char* inputPtr = input;
	int string = 0;


	// i - string index
	// j - symbol index
	// k - figure index, Data index later
	for (i = 0; i < stringsNum; i += 1) // input errors catch
	{
		cout << strings[i] << '\n';

		if (strings[i][0] == '(') {errorLog(i, 0, EMPTY_FIGURE_NAME); continue;}
		if (strings[i][0] == '\0') {errorLog(i, 0, EMPTY_STRING); continue;}

		j = -1;


		while (isalpha(strings[i][++j]));
		
		if (isdigit(strings[i][j])) {errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] == ')') {errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] != '(') {errorLog(i, j, INVALID_SYMBOL); continue;}


		for (k = 0; k < figuresNum; k += 1)
			if (stringsCompare(strings[i], figuresNames[k], '(')) 
			{
				k *= -1;
				break;
			};

		if (k > 0) {errorLog(i, 0, INVALID_FIGURE); continue;}
		k *= -1;
		//inputCode[i] = k;
		inputData[i] = new float[figuresDatas[k]];
		

		int dataNum = figuresDatas[k];

		bool isbreak = false;

		for(k = 0; k < dataNum; k += 1)
		{
			if (strings[i][j] == ' ' || strings[i][j] == '.') {errorLog(i, j, EXPECTED_COMMA); isbreak = true; break;}
			if (strings[i][j] != ',') {errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}
			if (isdigit(strings[i][++j])) {errorLog(i, j, EXPECTED_SPACE); isbreak = true; break;}
			if (strings[i][j] != ' ') {errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}

			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') {errorLog(i, j, EXPECTED_FLOAT_TYPE); isbreak = true; break;}
			if (strings[i][j] != '.') {errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}


			while (isdigit(strings[i][++j]));
		}
		if (isbreak) break;

		for (int cord = 0; cord != figuresCords[k]; cord += 1)
		{
			if (strings[i][j] == ')' && figuresCords[k] == -1) break;
			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') {errorLog(i, j, EXPECTED_FLOAT_TYPE); isbreak = true; break;}
			if (strings[i][j] != '.') {errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}


			while (isdigit(strings[i][++j]));

			if (cord == 0)
			{
				if (strings[i][j] == ',') {errorLog(i, j, EXPECTED_SPACE); isbreak = true; break;}
				if (strings[i][j] != ' ') {errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}
			}
		}
		if (isbreak) break;
		

		if (strings[i][j] != ')') {errorLog(i, j, EXPECTED_CLOSED_BRACKET); continue;}

		j += 1;
		
		if (strings[i][j] != '\0') {errorLog(i, j, EXPECTED_STRING_END); continue;}
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
				inputData[string][i] += digitFromChar(inputPtr[0]);
				inputData[string][i] *= 10;
			}
			inputPtr += 2;
		}
		inputPtr -= 2;

		string += 1;
	}
	
	
	//int windowHeight = 1200;
	//int windowWidth  = 1600;
	
	//int fps = 60;
}