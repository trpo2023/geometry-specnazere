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

	
}