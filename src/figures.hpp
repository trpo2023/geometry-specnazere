#pragma once

struct figure
{
    int cordsNum;
    int datasNum;

    int code;
    
    float* data;
    float** cords;

    float square();

    void setCord(int** cords);

    void setData(int* data);
};

struct circle:  public figure
{
    float square();

    void setCord(int** cords);

    void setData(int* data);

    circle(int code);
};

struct polygon: public figure
{
    float square();

    void setCord(int** cords);

    void setData(int* data);

    polygon(int code);
};