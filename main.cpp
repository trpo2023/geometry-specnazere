#include <iostream>
#include <graphics.h>

#define Names 0
#define Datas 1
#define Codes 2

#define square 0
#define circle 1

#define X 0
#define Y 0

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

int stringsCompare(char* firstString, char* secondString, char stopSymbol = '\0')
{
	int i = 0;
	int difNum = 0;
	
	while (
		(firstString[i]  != stopSymbol &&
		 secondString[i] != stopSymbol) &&
		(firstString[i]  != '\0'       &&
		 secondString[i] != '\0')
		)
	{
		if (firstString[i] != secondString[i])
		{
			difNum += 1;
		}
			
		i += 1;
	}
	return difNum;
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

	char input[500];
	int  i = 0;
	int  difNum;
	int  stringsNum = 1;
	
	FILE* file;
    file = fopen("figures.txt", "r");
    
    do {
		input[i] = fgetc(file);
		if (input[i] = '\n') stringsNum += 1;
	}
    while (input[i++] != EOF);
	input[--i] = '\0';
	
	int const figuresNum = 2;

	void* Data[2];

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
	
	void *figures[] = {
		figuresNames,
		figuresDatas,
		figuresCodes,
	};


	char* inputPtr = input;
	int stringPos = 0;

	while (inputPtr[1] != '\0')
	{
		for (i = 0; i < figuresNum; i += 1)
		{
			difNum = stringsCompare(inputPtr, figuresNames[i], '(');
			if (difNum <= 1) break;
		}
		if (difNum > 1) 
		{
			cout << "\nERROR! unknown figure's name at line " << stringPos + 1;
			return 1;
		}
		
		translatedInputCodes[stringPos] = figuresCodes[i];
		translatedInputNames[stringPos] = figuresNames[i];
		translatedInputData [stringPos] = new float[figuresDatas[i]];

		int  datas = figuresDatas[i];
		int  afterPointSymbols;
		bool wasPoint;

		for (; inputPtr[-1] != '('; inputPtr += 1);

		for (i = 0; i < datas; i += 1)
		{
			wasPoint = false;
			afterPointSymbols = 0;
			translatedInputData[stringPos][i] = 0;

			for (; inputPtr[0] != ',' && inputPtr[0] != ')'; inputPtr += 1)
			{
				if (inputPtr[0] == '.') 
				{                                    
					wasPoint = true; 
					continue;
				}
				
				if (!(isDigit(inputPtr[0]))) 
				{
					cout << "\ncol " << (int)(inputPtr - input) + 1 << " line " << stringPos + 1
						<< " expected digit, have \"" << inputPtr[0] << "\"";
					return 1;
				}
				
				if (wasPoint) afterPointSymbols += 1;
				translatedInputData[stringPos][i] +  digitFromChar(inputPtr[0]);
				translatedInputData[stringPos][i] *= 10;
			}
			inputPtr += 2;
		}
		inputPtr -= 2;

		stringPos += 1;
	}
	
	
	int windowHeight = 1200;
	int windowWidth  = 1600;
	
	int fps = 60;
}