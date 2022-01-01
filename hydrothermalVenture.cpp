#define p1 0
#define p2 0

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

void markLine(vector<vector<int>>&, int, int, int, int);
void markDiag(vector<vector<int>>&, int, int, int, int);

int main()
{
    // board[y1][x1] - board[y2][x2]
    vector<vector<int>> board(1000, vector<int>(1000, 0));
    string str;
    int overlap = 0;

    while (getline(cin, str))
    {
        int x1, y1, x2, y2;
        stringstream ss(str);

        ss >> x1;
        ss.ignore(1);
        ss >> y1;
        ss.ignore(4);
        ss >> x2;
        ss.ignore(1);
        ss >> y2;

        if (x1 == x2 || y1 == y2)
        {
            markLine(board, x1, y1, x2, y2);
        }
        #if p2
        else
        {
            markDiag(board, x1, y1, x2, y2);
        }
        #endif
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] > 1)
            {
                overlap++;
            }
            
        }
    }
    cout << overlap << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if(board[i][j]) {cout << board[i][j] << ' ';}
            else {cout << '.' << ' ';}
        }
        cout << endl;
    }
     
    return 0;
}

void markLine(vector<vector<int>>& board, int x1, int y1, int x2, int y2)
{
    if(x2 - x1) // Safety to not div by 0
    {
        if (!((y2 - y1) / (x2 - x1))) // Horizontal Line
        {
            if (x2 - x1 < 0)
            {
                for (int x = x2; x <= x1; x++)
                {
                    board[y1][x]++;
                }
            }
            else
            {
                for (int x = x1; x <= x2; x++)
                {
                    board[y1][x]++;
                }
            }
        }
    }
    else // Must be undefined - vertical
    {
        if (y2 - y1 < 0)
        {
            for (int i = y2; i <= y1; i++)
            {
                board[i][x1]++;  
            }
        }
        else
        {
            for (int i = y1; i <= y2; i++)
            {
                board[i][x1]++;  
            }
        }
    }
}

void markDiag(vector<vector<int>>& board, int x1, int y1, int x2, int y2)
{
    if (x2 - x1) // Safety, do not divide by 0
    {
        if((y2 - y1) / (x2 - x1) < 0)
        {
            if (x1 > x2 && y2 > y1)
            {
                for (int x = x2, y = y2; x <= x1, y >= y1; y--, x++)
                {
                    board[y][x]++;
                }
            }
            else
            {
                for (int y = y1, x = x1; y <= y2, x <= x2; y--, x++)
                {
                    board[y][x]++;
                }
            }
        }
        else
        {
            if (x2 < x1 && y2 < y1)
            {
                for (int y = y2, x = x2; y <= y1, x <= x1; y++, x++)
                {
                    board[y][x]++;
                }
            }
            else
            {
                for (int y = y1, x = x1; y <= y2, x <= x2; y++, x++)
                {
                    board[y][x]++;
                }
            }
        }
    }
}
