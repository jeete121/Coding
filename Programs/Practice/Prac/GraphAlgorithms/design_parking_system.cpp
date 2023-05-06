#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    int n1, n2, n3;
    ParkingSystem()
    {
    }
    ParkingSystem(int big, int medium, int small)
    {
        n1 = big;
        n2 = medium;
        n3 = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 && n1 > 0)
        {
            n1--;
            return true;
        }
        else if (carType == 1 && n1 == 0)
            return false;
        else if (carType == 2 && n2 > 0)
        {
            n2--;
            return true;
        }
        else if (carType == 2 && n2 == 0)
            return false;
        else if (carType == 3 && n3 > 0)
        {
            n3--;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    ParkingSystem parkingSystem(1, 1, 0);
    cout << "[";
    if (parkingSystem.addCar(1))
        cout << "true, ";
    else
        cout << "false, ";
    if (parkingSystem.addCar(2))
        cout << "true, ";
    else
        cout << "false, ";
    if (parkingSystem.addCar(3))
        cout << "true, ";
    else
        cout << "false, ";
    if (parkingSystem.addCar(1))
        cout << "true";
    else
        cout << "false";
    cout << "]";
    return 0;
}
