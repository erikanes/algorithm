#include <bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    for(auto& c : s) {
        int idx = index;

        while (idx > 0) {
            c = c+1 > 'z' ? 'a' : c+1;
            if (skip.end() != find(skip.begin(), skip.end(), c))
                continue;

            idx--;
        }
    }

    return s;
}