#include <iostream>

using namespace std;

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

main()
{
	cout << "Hello World!";
	
	char inputChar;
	char input[100];
	int  i = 0;
	int  lastEndline;
	char endWord[] = "end.";
	int  endWordLen = 4;
	int  difNum;
	
	while (true)
	{
		cin >> inputChar;
		if (inputChar = '\n')
		{
			difNum = stringsCompare(input + lastEndline, endWord);
			if (difNum = 0) break;
			lastEndline = i;
		}
		input[i++] = inputChar;
	}
	input[i - endWordLen] = '\0';
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
			if (difNum == 0) break;
		}

		if (difNum == 0) 
		{
			cout << "\nERROR! wrong input";
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
				if (inputPtr[0] == '.') {wasPoint = true; continue;}
				if (wasPoint) afterPointSymbols += 1;
				translatedInputData[stringPos][i] +  digitFromChar(inputPtr[0]);
				translatedInputData[stringPos][i] *= 10;
			}
		}

		stringPos += 1;
	}
}