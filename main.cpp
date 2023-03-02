#include <iostream>
#include <graphics.h>

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
	bool isntFinished = true;
	int i = 0;
	int difNum = 0;
	
	while (isntFinished)
	{
		if (firstString[i] != secondString[i] && isntFinished)
			difNum += 1;
			
		if (firstString[i] == stopSymbol || secondString[i] == stopSymbol)
			isntFinished == false;
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
	cout << "Hello World!";

	char input[100];
	int  i = 0;
	int  difNum;
	
	FILE* file;
    file = fopen("figures.txt", "r");
    
    do input[i] = fgetc(file);
	while (input[i++] != EOF);
	input[--i] = '\0';
	int N = i;
	
	int const figuresNum = 2;
	
	// 10 there is gag while not a dynamic
	float *translatedInputData [10]; //pointer to data
	char  *translatedInputNames[10]; //pointer to name
	char   translatedInputCodes[10]; //code of type
	
	char figuresNames[figuresNum][10] = {
		"square",
		"circle"
	};
	int  figuresDatas[figuresNum]     = {
		3, // X, Y, a
		3, // X, Y, r
	};
	int  figuresCodes[figuresNum]     = {
		'S', // X, Y, a
		'C', // X, Y, r
	};

	char* inputPtr = input;
	int stringPos = 0;

	while (inputPtr[0] != '\0')
	{
		for (i = 0; i < figuresNum; i += 1)
		{
			difNum = stringsCompare(inputPtr, figuresNames[i], '(');
			if (difNum <= 1) break;
		}

		if (difNum > 1) 
		{
			cout << "\nERROR! unknown figure's name";
			return 1;
		}

		translatedInputCodes[stringPos] = figuresCodes[i];
		translatedInputNames[stringPos] = figuresNames[i];
		translatedInputData [stringPos] = new float[figuresDatas[i]];

		int  datas = figuresDatas[i];
		int  afterPointSymbols;
		bool wasPoint;

		for (; inputPtr[0] != '('; inputPtr += 1);

		for (i = 0; i < datas; i += 1)
		{
			wasPoint = false;
			afterPointSymbols = 0;
			translatedInputData[stringPos][i] = 0;

			for (; inputPtr[0] != ',' || inputPtr[0] != ')'; inputPtr += 1)
			{
				if (!(isDigit(inputPtr[0]))) 
				{
					cout << "\ncol " << (int)(inputPtr - input) << " line " << stringPos
						<< " expected digit, have \"" << inputPtr[1] << "\"";
					return -1;
				}
				wasPoint = true; 
				if (inputPtr[0] == '.') 
				{
					inputPtr += 2;
					continue;
				}
				
				if (wasPoint) afterPointSymbols += 1;
				translatedInputData[stringPos][i] +  digitFromChar(inputPtr[0]);
				translatedInputData[stringPos][i] *= 10;
			}
		}

		stringPos += 1;
	}
	
	
	int windowHeight = 1200;
	int windowWidth  = 1600;
	
	int fps = 60;
	
	initwindow(windowHeight, windowWidth);
}