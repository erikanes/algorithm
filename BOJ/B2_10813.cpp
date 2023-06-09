#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    for (int i = 0; i <= 100; ++i) arr[i] = i;
    int N, M;
    cin >> N >> M;
    
    while (M--)
    {
        int i, j;
        cin >> i >> j;
        swap(arr[i], arr[j]);
    }
    
    for (int i = 1; i <= N; ++i) cout << arr[i] << ' ';
    
    return 0;
}