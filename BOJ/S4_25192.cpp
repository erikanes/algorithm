#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, ans = 0;
    set<string> s;
    cin >> n;
    
    while (n--)
    {
        string str;
        cin >> str;
        
        if (str == "ENTER")
        {
            ans += s.size();
            s.clear();
        }
        else
            s.insert(str);
    }
    
    ans += s.size();
    cout << ans << '\n';
    
    return 0;
}