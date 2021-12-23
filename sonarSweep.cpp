#define p1 0
#define p2 0

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{   
    int increasedCount = 0;
    int n;

    #if p1
    int prev;
    
    cin >> prev;
    while (cin >> n)
    {
        if(prev < n)
        {
            increasedCount++;
        }
        prev = n;
    }
    #endif
    

    #if p2
    vector<int> numStack;
    vector<int> sumStack;

    while (cin >> n)
    {
        numStack.push_back(n);
        
        if (numStack.size() == 3)
        {
            int sum = 0;
            for (int idx = 0; idx < 3; idx++)
            {
                sum += numStack[idx];
            }
            if (sumStack.size())
            {
                if(sumStack.front() < sum)
                {
                    increasedCount++;
                }
                sumStack.clear();
            }
            
            sumStack.push_back(sum);
            numStack.erase(numStack.begin(), numStack.begin() + 1);
        }
    }
    #endif

    cout << increasedCount << endl;
    return 0;
}