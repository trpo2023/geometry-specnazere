#include <cmath>

#include "figures.hpp"

#define pi 3.14159

struct figure
{
    int cordsNum;
    int datasNum;

    float square();

    void setCord(int** cords);

    void setData(int* data);
};

struct circle: figure
{
    int data[1];
    int cords[1][2];

    float square()
    {
        return data[1] * pi;
    }

    void setCord(int** cords)
    {
        this->cords[0][0] = cords[0][0];
        this->cords[0][1] = cords[0][1];
    }

    void setData(int* data)
    {
        this->data[0] = data[0];
    }
};

struct polygon: figure
{
    int** cords;

    float square();

    void  setCord(int** cords)
    {
        this->cords = new int*[cordsNum];

        for (int cord = 0; cord < cordsNum; cord += 1)
        {
            this->cords[cord] = new int[2];

            this->cords[cord][0] = cords[cord][0];
            this->cords[cord][1] = cords[cord][1];
        }
    }
};