
#include <string>
#include <iostream>
using namespace std;

class BASE
{
public:
    void set_status(int a_status);
    void set_location(int a_x, int a_y)
    {
        x = a_x;
        y = a_y;
    }

protected:
    int x;
    int y;
    int status;
};

class DERIVED : public BASE
{
public:
    void set_color(int a_color)
    {
        color = a_color;
        x = 9;
        y = 11;
    }

private:
    int color;
};

int main()
{
    BASE b1;
    return 1;
}
