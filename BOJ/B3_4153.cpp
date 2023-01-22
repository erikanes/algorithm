#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    while(1) {
        int line[3];
        cin >> line[0] >> line[1] >> line[2];
        if (line[0]+line[1]+line[2] == 0) break;
        
        sort(line, line+3);
        
        if (line[0]*line[0] + line[1]*line[1] == line[2]*line[2])
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}