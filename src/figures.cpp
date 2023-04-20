#include <cmath>

#include "figures.hpp"

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

void  circle::setCord(int** cords)
{
    this->cords[0][0] = cords[0][0];
    this->cords[0][1] = cords[0][1];
}

void  circle::setData(int* data)
{
    this->data[0] = data[0];
}


polygon::polygon(int code)
{
    this->code = code;

    this->cordsNum = -1;
    this->datasNum = 0;
}

void  polygon::setCord(int** cords)
{
    this->cords = new float*[cordsNum];

    for (int cord = 0; cord < cordsNum; cord += 1)
    {
        this->cords[cord] = new float[2];

        this->cords[cord][0] = cords[cord][0];
        this->cords[cord][1] = cords[cord][1];
    }
}
