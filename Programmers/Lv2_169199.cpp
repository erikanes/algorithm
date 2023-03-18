#include <bits/stdc++.h>
using namespace std;

#define DIST cur.first
#define X cur.second.first
#define Y cur.second.second
#define DX x+dx[i]
#define DY y+dy[i]
#define CONDITION !(DX>=w||DX<0||DY>=h||DY<0||board[DY][DX]=='D')

using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

using namespace std;

P findR(vector<string>& board)
{
    for (int y = 0; y < board.size(); ++y)
        for (int x = 0; x < board[y].size(); ++x)
            if (board[y][x] == 'R')
                return {x, y};
}

int solution(vector<string> board) {

    PP start = {0,findR(board)};
    int w = board[0].size();
    int h = board.size();

    queue<PP> q;
    q.push(start);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int x = X, y = Y;
            while (CONDITION)
            {
                x += dx[i];
                y += dy[i];
            }
            if (board[y][x] == 'X')
                continue;

            if (board[y][x] == 'G')
                return DIST+1;

            board[y][x] = 'X';
            q.push({DIST+1,{x,y}});
        }
    }

    return -1;
}