#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    
    queue<pair<long long,int>> q;
    q.push({a,1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if (cur.first == b) {
            cout << cur.second;
            return 0;
        }
        else if (cur.first > b)
            continue;
        
        q.push({cur.first*2, cur.second+1});
        q.push({cur.first*10+1, cur.second+1});
    }
    
    cout << -1;
    return 0;
}