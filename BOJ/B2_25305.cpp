#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    vector<int> v;
    cin >> n >> k;
    while (n--) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<>());
    cout << v[k-1];
    
    return 0;
}