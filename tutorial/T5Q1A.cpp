#include <iostream>
using namespace std;

class Fraction {
    public:
        Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}
        Fraction add(Fraction f) {
            int commonDenominator = denominator * f.denominator;
            int newNumerator = (numerator * f.denominator) + (f.numerator * denominator);
            return Fraction(newNumerator, commonDenominator);
        }
        Fraction multiply(Fraction f) {
            return Fraction(numerator * f.numerator, denominator * f.denominator);
        }
        void display(void) const {
            cout << numerator << "/" << denominator << endl;
        }
        
    private:
        int numerator;
        int denominator;
};

int main()
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result;

    cout << "f1: ";
    f1.display();

    cout << "f2: ";
    f2.display();

    cout << "f1 + f2: ";
    result = f1.add(f2);
    result.display();

    cout << "f1 * f2: ";
    result = f1.multiply(f2);
    result.display();

    return 0;
}