#include <bits/stdc++.h>
using namespace std;
#define X cur.first.first
#define Y cur.first.second
#define COST cur.second
using P = pair<pair<int,int>,int>;
int dx[6] = {-2, -2, 0, 2, 2, 0};
int dy[6] = {1, -1, -2, -1, 1, 2};
bool graph[201][201];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    
    graph[c1][r1] = true;
    queue<P> q;
    q.push({{r1,c1},0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (int i = 0; i < 6; ++i) {
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[ny][nx]) continue;
            if (nx == r2 && ny == c2) {
                cout << COST+1;
                return 0;
            }
            graph[ny][nx] = true;
            q.push({{nx,ny},COST+1});
        }
    }
    
    cout << -1;
    
    return 0;
}