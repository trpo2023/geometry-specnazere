#include <cmath>
#include <iostream>

#include "figures.hpp"

using namespace std;

#define pi 3.14159


circle::circle(int code)
{
    this->data = new float;

    this->cords = new float*;
    this->cords[0] = new float[2];
    
    this->code = code;
    this->figureCode = 1;

    this->cordsNum = 1;
    this->datasNum = 1;
}

polygon::polygon(int code)
{
    this->code = code;
    this->figureCode = 0;

    this->cordsNum = -1;
    this->datasNum = 0;
}

void  figure::squareInit()
{
    switch (this->figureCode)
    {
        case 0:
        {
            float square = 0;

            for (int i = 0; i < this->cordsNum - 1; i += 1)
            {
                square += this->cords[i][0] * this->cords[i + 1][1] 
                    + this->cords[this->cordsNum - 1][0] * this->cords[0][1];
            }
            for (int i = 1; i < this->cordsNum; i += 1)
            {
                square -= this->cords[i][0] * this->cords[i - 1][1] 
                    - this->cords[0][0] * this->cords[this->cordsNum - 1][1];
            }

            this->square = square;
            break;
        }
        case 1:
        {
            this->square = this->data[0] * this->data[0] * pi;
            break;
        }
    }
}

void  figure::print()
{
    cout << this->code << ": ";

    switch (this->figureCode)
    {
        case 0: cout << "polygon";
        case 1: cout << "circle";
    }
    cout << '\n';

    if (this->datasNum == 0)
    {
        cout << "have no data" << '\n';
    } 
    else
    {
        cout << "data:" << '\n';
        for (int i = 0; i < this->datasNum; i += 1)
        {
            cout << i + 1 << " = " << this->data[i];
        }
    }
    cout << '\n';
    cout << "points:" << '\n';

    cout << "x";
    cout.width(10);
    cout << "y" << '\n';
    
    for (int cord = 0; cord < this->cordsNum; cord += 1)
    {
        cout << this->cords[cord][0];
        cout.width(10);
        cout << this->cords[cord][1] << '\n';
    }

    cout << "square is: " << this->square << '\n';
}

void  figure::setCord(float** cords)
{
    switch(this->figureCode)
    {
        case 0:
        {
            this->cords = new float*[this->cordsNum];
            
            for (int cord = 0; cord < this->cordsNum; cord += 1)
            {
                this->cords[cord] = new float[2];

                this->cords[cord][0] = cords[cord][0];
                this->cords[cord][1] = cords[cord][1];
            }
            break;
        }
        case 1:
        {
            this->cords[0][0] = cords[0][0];
            this->cords[0][1] = cords[0][1];
            break;
        }
    }
}

void  figure::setData(float* data)
{
    switch(this->figureCode)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            this->data[0] = data[0];
            break;
        }
    }
}