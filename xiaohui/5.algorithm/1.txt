

黑白棋，又叫翻转棋（Reversi）、苹果棋或奥赛罗棋（Othello）。棋盘共有8行8列共64格。
开局时，棋盘正中央的4格先置放黑白相隔的4枚棋子。双方轮流落子，只要落子和棋盘上任一枚己方的棋子在一条线上（横、直、斜线皆可）夹着对方棋子，就能将对方的这些棋子转变为我己方（翻面即可）。如果在任一位置落子都不能夹住对手的任一颗棋子，就要让对手下子。当双方皆不能下子时，游戏就结束，子多的一方胜。
现在给你一个8x8的棋局，以及下一步玩家的落子位置。请输出翻转好的新棋局。

#include <iostream>
#include <vector>
using namespace std;
 
#define N 8
 
void solve(vector<vector<char> > & map, int x, int y, char c)
{
    int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
    map[x][y] = c;
 
    for (int i = 0; i < 8; ++i)
    {
        int count = 1, flag = 0;
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (c == '*')
        {
            while (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '+')
                nx += dir[i][0], ny += dir[i][1];
            if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '*')
            {
                nx -= dir[i][0], ny -= dir[i][1];
                while (map[nx][ny] == '+')
                {
                    map[nx][ny] = '*';
                    nx -= dir[i][0], ny -= dir[i][1];
                }
            }
        }
        else if (c == '+')
        {
            while (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '*')
                nx += dir[i][0], ny += dir[i][1];
            if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && map[nx][ny] == '+')
            {
                nx -= dir[i][0], ny -= dir[i][1];
                while (map[nx][ny] == '*')
                {
                    map[nx][ny] = '+';
                    nx -= dir[i][0], ny -= dir[i][1];
                }
            }
        }
    }
}
 
int main()
{
    char ch;
    while (cin >> ch)
    {
        vector<vector<char> > map(10, vector<char>(10, '.'));
        map[1][1] = ch;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (i == 1 && j == 1) continue;
                cin >> ch;
                map[i][j] = ch;
            }
 
        int x, y;
        cin >> x >> y >> ch;
        solve(map, x, y, ch);
 
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
                cout << map[i][j];
            cout << endl;
        }
        cout << endl;
    }
 
    return 0;
}