#include <iostream>
using namespace std;

class Temperature{
    private:
        float tempCel, tempFar;
    public:
        Temperature() {
            tempCel = 0.0;
            tempFar = 32.0;
        };

        Temperature(char symbol, float temp) {
            if (symbol == 'C' || symbol == 'c') {
                tempCel = temp;
                tempFar = (temp * 9.0 / 5.0) + 32.0;
            } 
            else if (symbol == 'F' || symbol == 'f') {
                tempFar = temp;
                tempCel = (temp - 32.0) * 5.0 / 9.0;
            }
        };

        float getCels() {
            return tempCel;
        };

        float getFar() {
            return tempFar;
        };

        void equal(Temperature t) {
            tempCel = t.getCels();
            tempFar = t.getFar();
        };
};

int main()
{
	Temperature t1('C',100),t2('F',100);

	cout<<"t1 = "<<t1.getCels()<<" C\n";
	cout<<"t1 = "<<t1.getFar()<<" F\n";

	cout<<"t2 = "<<t2.getCels()<<" C\n";
	cout<<"t2 = "<<t2.getFar()<<" F\n";

	t1.equal(t2);   // assign value in t2 to t1
	cout<<"After assigning t2 to t1"<<endl;

	cout<<"t1 = "<<t1.getCels()<<" C\n";
	cout<<"t1 = "<<t1.getFar()<<" F\n";
	return 0;
}
