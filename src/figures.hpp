#pragma once

struct figure
{
    int cordsNum;
    int datasNum;

    int code;
    int figureCode;
    
    float* data;
    float** cords;

    float square;

    void squareInit();

    void setCord(float** cords);

    void setData(float* data);

    void print();
};

struct circle:  public figure
{
    circle(int code);
};

struct polygon: public figure
{
    polygon(int code);
};