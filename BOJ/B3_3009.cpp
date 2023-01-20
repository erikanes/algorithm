#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[3][2];
    cin >> arr[0][0] >> arr[0][1];
    cin >> arr[1][0] >> arr[1][1];
    cin >> arr[2][0] >> arr[2][1];

    cout << (arr[0][0] ^ arr[1][0] ^ arr[2][0]) << ' ';
    cout << (arr[0][1] ^ arr[1][1] ^ arr[2][1]);

    return 0;
}