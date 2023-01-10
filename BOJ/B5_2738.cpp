#include <bits/stdc++.h>
using namespace std;

int arr1[100][100];
int arr2[100][100];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> arr1[i][j];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> arr2[i][j];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << arr1[i][j] + arr2[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}