#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    map<string, int> m = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
     };
    for_each(m.begin(), m.end(), [&s](auto a){ s = regex_replace(s, regex(a.first), to_string(a.second)); });

    return stoi(s);
}