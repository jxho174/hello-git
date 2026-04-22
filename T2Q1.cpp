#include <iostream>
using namespace std;
int factorial(int num);

int main()
{
    int x=4;
    cout<<"\nFactorial of "<<x<<" = "<<factorial(x) << endl;
    return 0;
}

int factorial(int num)
{
    if(num==0){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}