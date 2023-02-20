#include <iostream>

int stringsCompare(char* firstString, char* secondString)
{
	bool isntFinished = true;
	int i = 0;
	int difNum = 0;
	
	while (isntFinished)
	{
		if (firstString[i] != secondString[i] && isntFinished)
			difNum += 1;
			
		if (firstString[i] == '\0' || secondString[i] == '\0')
			isntFinished == false;
	}
	
	return difNum;
}

main()
{
	cout << "Hello World!";
}