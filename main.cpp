#include <iostream>

#include "src/errors_catch.h"
#include "src/strings.h"
#include "src/figures.hpp"

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

#define POLYGON 0
#define CIRCLE  1

#define X 0
#define Y 0

int main()
{
	cout << "Start sucess\n";

	char  input[5000];  // up to 5000 symbols while not dynamic
	char* strings[50]; // up to 50 strings while not dynamic
	//int  difNum;
	int  stringsNum = 1;

	FILE* file;
    file = fopen("figuresCorrect.txt", "r");

	cout << "File open" << '\n';

	strings[0] = input;

	int j = 1;
	int i = 0;
    do {
		input[i] = fgetc(file);
		if (input[i] == '\n') 
		{	
			input[i] = '\0';
			stringsNum += 1;
			strings[j] = input + i + 1;
			j += 1;
		}
	}
    while (input[i++] != EOF);

	input[--i] = '\0';
	
	cout << "File readed" << '\n';

	int const figuresNum = 2;
	

	char figuresNames[figuresNum][8] = {
		"polygon",
		"circle",
	};
	

	char* inputPtr = input;
	int string = 0;


	figure* figures = new figure[stringsNum];

	// corrects - figures[] index
	// i - string index
	// j - symbol index
	// k - figure index, Data index later
	int correct = 0;
	for (int i = 0, j, k = 0; i < stringsNum; i += 1) // input errors catch
	{
		cout << strings[i] << '\n';

		if (strings[i][0] == '(') 
			{errorLog(i, 0, EMPTY_FIGURE_NAME); continue;}
		if (strings[i][0] == '\0') 
			{errorLog(i, 0, EMPTY_STRING); continue;}

		j = -1;

		while (isalpha(strings[i][++j]));
		
		if (isdigit(strings[i][j])) 
			{errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] == ')') 
			{errorLog(i, j, EXPECTED_OPENED_BRACKET); continue;}
		if (strings[i][j] != '(') 
			{errorLog(i, j, INVALID_SYMBOL); continue;}

		j += 1;

		for (k = 0; k < figuresNum; k += 1)
			if (stringsCompare(strings[i], figuresNames[k], '(')) 
			{
				k *= -1;
				break;
			};

		if (k > 0) {errorLog(i, 0, INVALID_FIGURE); continue;}
		k *= -1;
		
		switch (k)
		{
			case POLYGON: 
			{
				figures[correct] = polygon(i);
				break;
			}
			case CIRCLE : 
			{
				figures[correct] = circle(i);  
				break;
			}
		}

		bool isbreak = false;

		for(k = 0; k != figures[correct].datasNum; k += 1)
		{
			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') 
				{errorLog(i, j, EXPECTED_FLOAT_TYPE); isbreak = true; break;}
			if (strings[i][j] != '.') 
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}

			while (isdigit(strings[i][++j]));
			
			if (strings[i][j] == ' ' || strings[i][j] == '.') 
				{errorLog(i, j, EXPECTED_COMMA); isbreak = true; break;}
			if (strings[i][j] != ',') 
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}
			
			j += 1;
		}
		if (isbreak) continue;
		
		
		int totalCords;

		for (int cord = 0; cord != figures[correct].cordsNum; cord += 1)
		{
			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') 
				{errorLog(i, j, EXPECTED_FLOAT_TYPE); isbreak = true; break;}
			if (strings[i][j] != '.') 
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}

			while (isdigit(strings[i][++j]));
			
			if (strings[i][j] == ',') 
				{errorLog(i, j, EXPECTED_SPACE); isbreak = true; break;}
			if (strings[i][j] != ' ') 
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}


			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ' ') 
				{errorLog(i, j, EXPECTED_FLOAT_TYPE); isbreak = true; break;}
			if (strings[i][j] != '.') 
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}

			while (isdigit(strings[i][++j]));

			if (strings[i][j] == ')' && (figures[correct].cordsNum == -1 || figures[correct].cordsNum == cord + 1))
				{break;}
			 
			if (strings[i][j] != ',' && cord + 1 != figures[correct].cordsNum)
				{errorLog(i, j, EXPECTED_COMMA); isbreak = true; break;}

			j += 1;

			if (isdigit(strings[i][j]))
				{errorLog(i, j, EXPECTED_SPACE); isbreak = true; break;}
			if (strings[i][j] != ' ')
				{errorLog(i, j, INVALID_SYMBOL); isbreak = true; break;}
			
			j += 1;
			if (figures[i].cordsNum == -1) totalCords += 1;
		}
		if (isbreak) continue;
		

		if (strings[i][j] != ')') {errorLog(i, j, EXPECTED_CLOSED_BRACKET); continue;}

		j += 1;
		
		if (strings[i][j] != '\0') {errorLog(i, j, EXPECTED_STRING_END); continue;}

		if (figures[i].cordsNum == -1) figures[i].cordsNum = totalCords;
		cout << "no errors\n";
		correct += 1;
	}

	cout << "input checked" << '\n';

	if (correct != stringsNum)
	{
		cout << "\ninput errors detected, ending\n";
		cout << correct << ' ' << stringsNum;
		return 1;
	}

	for (int figure = 0; figure < stringsNum; figure += 1)
	{
		j = 0;
		float*  dataArr  = new float [figures[figure].datasNum];
		float** cordsArr = new float*[figures[figure].cordsNum];

		while(!isdigit(strings[figure][++j]));

		for (int data = 0; data < figures[figure].datasNum; data += 1)
		{
			dataArr[data] = strToFloat(strings[figure] + j);
			while (isDigit(strings[figure][j]) || strings[figure][j] == '.') j += 1;
			j += 2;
		}
		figures[figure].setData(dataArr);

		for (int cord = 0; cord < figures[figure].cordsNum; cord += 1)
		{
			cordsArr[cord][0] = strToFloat(strings[figure] + j);
			while (isDigit(strings[figure][j]) || strings[figure][j] == '.') j += 1;
			j += 1;
			cordsArr[cord][1] = strToFloat(strings[figure] + j);
			while (isDigit(strings[figure][j]) || strings[figure][j] == '.') j += 1;
			j += 2;
		}

		figures[figure].setCord(cordsArr);

		figures[figure].print();
	}
}