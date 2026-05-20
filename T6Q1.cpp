#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class SPowerData {
    public:
        float m_Amp;
        float m_Res;
        float m_Power;
};

class CPowerInfo {
    private:
        fstream m_File;
        int numElem;
        SPowerData *m_power_array; // why pointer ? to store array of struct variables

    public:
        void LoadData(string pFile, int numElements)
        {
            m_File.open(pFile);
            cout << "\n Total elements :" << numElements;
            numElem = numElements;
            m_power_array = new SPowerData[numElements];

            for (int i = 0; i < numElements; i++)
            {
                m_File >> m_power_array[i].m_Amp;
                m_File >> m_power_array[i].m_Res;
                m_power_array[i].m_Power = pow(m_power_array[i].m_Amp, 2) * m_power_array[i].m_Res;

                cout << "\n" 
                    << m_power_array[i].m_Amp << "\t" << m_power_array[i].m_Res;
            }

            m_File.close();
        }

        int getNumElements(string pFile) 
        {
            m_File.open(pFile);
            int count = 0;
            float d1, d2;

            while (m_File >> d1 >> d2) {
                count++;
            }
            m_File.close();
            return count;
        }

        void FindMinMaxPower(float &minpower, float &maxpower)
        {
            minpower = 10000;
            maxpower = -10000;

            for (int i = 0; i < numElem; i++)
            {
                if (m_power_array[i].m_Power < minpower) {
                    minpower = m_power_array[i].m_Power;
                }
                if (m_power_array[i].m_Power > maxpower) {
                    maxpower = m_power_array[i].m_Power;
                }
            }
        }
};

int main() 
{
    CPowerInfo cw;
    int numElements = cw.getNumElements("AmpRes.txt"); // try implement this function
    cw.LoadData("AmpRes.txt", numElements);
    float minpower, maxpower;

    cw.FindMinMaxPower(minpower, maxpower);
    cout << "\n The minimum power = " << minpower;
    cout << "\n The maximum power = " << maxpower;
    cout << endl;

    return 0;

}