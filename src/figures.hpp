struct figure
{
    float square();

    void setCord(int** cords);

    void setData(int* data);
};

struct circle: figure
{
    float square();

    void setCord(int** cords);

    void setData(int* data);
};

struct polygon: figure
{
    float square();

    void  setCord(int** cords);
};