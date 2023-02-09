#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    stack<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        int h;
        cin >> h;
        
        while (!s.empty()) {
            if (s.top().second > h) {
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }
        
        if (s.empty()) cout << 0 << ' ';
        
        s.push({i, h});
    }
    
    return 0;
}