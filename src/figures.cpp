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

    this->cordsNum = 1;
    this->datasNum = 1;
}

float circle::square()
{
    return this->data[1] * pi;
}

void  circle::print()
{
    cout << this->code << ": polygon" << '\n'
         << "data:" << '\n'
         << "radius = " << this->data[0] << '\n'

         << "points cords:" << '\n'
         << "x" << cout.width(10) << "y" << '\n';
    
    for (int cord = 0; cord < this->cordsNum; cord += 1)
    {
        cout << this->cords[cord][0] << cout.width(10) << this->cords[cord][1] << '\n';
    }
}

void  circle::setCord(float** cords)
{
    this->cords[0][0] = cords[0][0];
    this->cords[0][1] = cords[0][1];
}

void  circle::setData(float* data)
{
    this->data[0] = data[0];
}


polygon::polygon(int code)
{
    this->code = code;

    this->cordsNum = -1;
    this->datasNum = 0;
}

void  polygon::print()
{
    cout << this->code << ": polygon" << '\n'
         << "have no data" << '\n'
         << "points cords:" << '\n'
         << "x" << cout.width(10) << "y" << '\n';
    
    for (int cord = 0; cord < this->cordsNum; cord += 1)
    {
        cout << this->cords[cord][0] << cout.width(10) << this->cords[cord][1] << '\n';
    }
}

void  polygon::setCord(float** cords)
{
    this->cords = new float*[cordsNum];

    for (int cord = 0; cord < cordsNum; cord += 1)
    {
        this->cords[cord] = new float[2];

        this->cords[cord][0] = cords[cord][0];
        this->cords[cord][1] = cords[cord][1];
    }
}
