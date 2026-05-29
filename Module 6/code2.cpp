#include <iostream>
#include <cstring>
using namespace std;

class Pen
{
public:
    void set_status(int a_x) { x = a_x; }

protected:
    int x;
    int status;
};

class CPen : public Pen
{
public:
    void set_color(int a_color)
    {
        color = a_color;
        status = 0;
    }

protected:
    int color;
};

class Pilot : public CPen
{
public:
    void draw()
    {
        color = 1;
        status = 2;
        x = 99;
    }

private:
    char modelName[10];
    int productYear;
};

int main()
{
    Pilot p;
    p.draw();
    return 1;
}
