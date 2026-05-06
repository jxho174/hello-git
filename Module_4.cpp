#include <iostream>
using namespace std;

class Time{
    private:
        int day, hour, minute, second;

    public:
        Time() {
            day = 0;
            hour = 0;
            minute = 0;
            second = 0;
        }

        Time(int d, int h, int m, int s){
            day = d;
            hour = h;
            minute = m;
            second = s;
        }

        void displayTime(){
            cout << "Day: \t" << day << endl;
            cout << "Hour: \t" << hour << endl;
            cout << "Minute: " << minute << endl;
            cout << "Second: " << second << endl;
        }
};


int main()
{
    Time t1;
    t1.displayTime();

    return 0;
}