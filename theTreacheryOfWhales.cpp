#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

void partOne(vector<int> v)
{
    int least_fuel_pos = 2;
    int fuelCost = 0;
    int min = 0;

    for (int pos = 0; pos < v.size(); pos++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            fuelCost += abs(v[i] - pos);
        }
        if (pos == 0)
        {
            min = fuelCost;
        }
        if (fuelCost < min)
        {
            min = fuelCost;
        }
        fuelCost = 0;
    }

    cout << min << endl;
}

void partTwo(vector<int> v)
{
    int fuelCost = 0;
    int sum = 0;
    int min = 0;

    for (int horiz_pos = 0; horiz_pos < v.size(); horiz_pos++)
    {
        for (int pos = 0; pos < v.size(); pos++)
        {
            sum = 0;
            for (int i = 0; i <= abs(v[pos] - horiz_pos); i++)
            {
                sum += i;
            }
            fuelCost += sum;
        }
        if (horiz_pos == 0)
        {
            min = fuelCost;
        }
        if (fuelCost < min)
        {
            min = fuelCost;
        }
        fuelCost = 0;
    }
    cout << min << endl;
}

int main()
{
    vector<int> v;

    string str;
    getline(cin, str);
    stringstream ss(str);
    int n;

    while (ss >> n)
    {
        ss.ignore(1);
        v.push_back(n);
    }

    partOne(v);
    partTwo(v);

    return 0;
}
