#pragma once

struct figure
{
    int cordsNum;
    int datasNum;

    int code;
    
    float* data;
    float** cords;

    float square();

    void setCord(float** cords);

    void setData(float* data);

    void print();
};

struct circle:  public figure
{
    float square();

    void setCord(float** cords);

    void setData(float* data);

    void print();

    circle(int code);
};

struct polygon: public figure
{
    float square();

    void setCord(float** cords);

    void setData(float* data);

    void print();

    polygon(int code);
};