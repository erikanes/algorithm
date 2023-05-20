#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, 0));
    
    for(int i = 1; i <= s1.size(); ++i)
    {
        for(int j = 1; j <= s2.size(); ++j)
        {
            if(s1[i-1] == s2[j-1]) v[i][j] = v[i-1][j-1] + 1;
            else v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    
    cout << v[s1.size()][s2.size()];

    return 0;
}