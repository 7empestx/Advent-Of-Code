#define p1 0
#define p2 0

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <bitset>

using namespace std;

#if p1
int main()
{   
    unordered_map<int, int> map;
    string gammaRate;
    string epsilonRate;
    string str;
    int pos = 0;
    int lineCount = 0;

    while(getline(cin, str))
    {
        stringstream ss(str);
        char ch;
        pos = 0;
        while (ss >> ch)
        {
            if (ch == '0')
            {
                map[pos]++;
            }
            pos++;
        }
        lineCount++;
    } 

    for (int i = 0; i < pos; i++)
    {
        if (map.at(i) > lineCount - map.at(i))
        {
            gammaRate.push_back('0');
            epsilonRate.push_back('1');
        }
        else
        {
            gammaRate.push_back('1');
            epsilonRate.push_back('0');
        }
    }

    cout << bitset<64>(gammaRate).to_ullong() * bitset<64>(epsilonRate).to_ullong() << endl;

    return 0;
}
#endif

#if p2
void updateCounterArray(vector<int>&, vector<string>);
void processOXYRating(vector<int>&, vector<string>&, int);
void processC02Rating(vector<int>&, vector<string>&, int);
void charToReplace(vector<string>&, int, char);

int main()
{   
    string str;
    vector<int> zeroCount(5, 0);
    vector<string> O2_vec;
    vector<string> c02_vec;
    int pos = 0;

    while (getline(cin, str))
    {
        stringstream ss(str);
        char ch;
        while (ss.get(ch))
        {
            if(ch == '0')
            {
                zeroCount[pos]++;
            }
            pos++;
        }
        O2_vec.push_back(str);
        pos = 0;
    }
    c02_vec = O2_vec;

    for (int i = 0; i < O2_vec[0].size(); i++)
    {
        processOXYRating(zeroCount, O2_vec, i);
    }
    for (int i = 0; c02_vec.size() != 1; i++)
    {
        processC02Rating(zeroCount, c02_vec, i);
    }

    string oxygen_generator_rating = O2_vec[0];
    string c02_scrubber_rating = c02_vec[0];

    cout << bitset<64>(oxygen_generator_rating).to_ullong() * bitset<64>(c02_scrubber_rating).to_ullong() << endl;
    
    return 0;
}

void processOXYRating(vector<int>& zeroCount, vector<string>& vec, int pos)
{
    vector<string> newVec;
    updateCounterArray(zeroCount, vec);

    // zero_count > ones_count
    if (zeroCount[pos] > vec.size() - zeroCount[pos])
    {
        charToReplace(vec, pos, '0');
    }
    // zero_count < ones_count || zero_count == ones_count 
    else
    {
        charToReplace(vec, pos, '1');
    }    
}

void processC02Rating(vector<int>& zeroCount, vector<string>& vec, int pos)
{
    updateCounterArray(zeroCount, vec);
    
    // zero_count > ones_count
    if (zeroCount[pos] > vec.size() - zeroCount[pos])
    {
        charToReplace(vec, pos, '1');
    }
    // zero_count < ones_count || zero_count == ones_count 
    else
    {
        charToReplace(vec, pos, '0');
    } 
}

void charToReplace(vector<string>& vec, int pos, char ch)
{
    vector<string> newVec;
    for (int i = 0; i < vec.size(); i++)
    {
        string temp = vec[i];
        if (temp[pos] == ch)
        {
            newVec.push_back(temp);
        }
    }
    vec.swap(newVec);
}

void updateCounterArray(vector<int>& zeroCount, vector<string> vec)
{
    string str = vec[0];
    int pos = 0;
    for (int i = 0; i < str.size(); i++)
    {
        zeroCount[i] = 0;
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        string str = vec[i];

        for (int pos = 0; pos < str.size(); pos++)
        {
            if(str[pos] == '0')
            {
                zeroCount[pos]++;
            }
        }
    }
}

#endif