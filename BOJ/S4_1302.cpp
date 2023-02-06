#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    map<string, int> m;
    while (n--) {
        string s;
        cin >> s;
        
        m[s] += 1;        
    }
    
    pair<string, int> answer("", 0);
    for (const auto& p : m)
        if (p.second > answer.second) answer = p;
    
    cout << answer.first;
    
    return 0;
}