#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, p;
    cin >> n >> t >> p;

    vector<int> v;
    while (n--) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int rank = lower_bound(v.begin(), v.end(), t, greater<int>()) - v.begin() + 1;
    int check = upper_bound(v.begin(), v.end(), t, greater<int>()) - v.begin() + 1;
    
    if (rank <= p && check <= p)
        cout << rank;
    else
        cout << -1;

    return 0;
}