#define p1 1
#define p2 0

#include <iostream>

using namespace std;

#if p1
char transmission(string);
void pilot(char, int, int&, int&);
#endif

#if p2
char transmission(string);
void pilot(char, int, int&, int&, int&);
#endif

int main()
{   
    string direction;
    int distance;
    int hori = 0;
    int dept = 0;

    #if p2
    int aim = 0;
    #endif
    
    while (cin >> direction >> distance)
    {
        #if p1
        pilot(transmission(direction), distance, hori, dept);
        #endif
        
        #if p2
        pilot(transmission(direction), distance, hori, dept, aim);
        #endif
    }

    cout << hori * dept << endl;
    
    return 0;
}

char transmission(string str)
{
    char returnCondition;

    if (str == "forward")
    {
        returnCondition = 'F';
    }
    if (str == "down")
    {
        returnCondition = 'D';
    }
    if (str == "up")
    {
        returnCondition = 'U';
    }

    return returnCondition;
}

#if p1
void pilot(char dir, int dist, int& hori, int& dept)
{
    switch (dir)
    {
        case 'F': hori += dist;
            break;
        case 'D': dept += dist;
            break;
        case 'U': dept -= dist;
            break;
        default:
            break;
    }
}
#endif

#if p2
void pilot(char dir, int dist, int& hori, int& dept, int& aim)
{
    switch (dir)
    {
        case 'F': 
            hori += dist;
            dept += aim * dist;
            break;
        case 'D':
            aim += dist;
            break;
        case 'U':
            aim -= dist;
            break;
        default:
            break;
    }
}
#endif







