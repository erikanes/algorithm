#include <bits/stdc++.h>
using namespace std;

int arr[5][5];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> arr[j][i];
    }
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x >= n || x < 0 || y >= n || y < 0 || arr[x][y] == 0)
            continue;
        
        if (arr[x][y] == -1) {
            cout << "HaruHaru";
            return 0;
        }
        
        int dest = arr[x][y];
        q.push({x+dest, y});
        q.push({x, y+dest});
    }
    
    cout << "Hing";
    return 0;
}