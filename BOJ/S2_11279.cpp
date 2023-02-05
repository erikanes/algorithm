#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<>> q;
    vector<int> v;
    while(n--) {
        int x;
        cin >> x;
        
        if (x == 0) {
            if (q.empty()) v.emplace_back(0);
            else {
                v.emplace_back(q.top());
                q.pop();
            }
        }
        else
            q.push(x);      
    }
    
    for (const auto& i : v)
        cout << i << '\n';
    
    return 0;
}