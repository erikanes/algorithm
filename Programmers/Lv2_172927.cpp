#include <bits/stdc++.h>

using namespace std;

int convert(const string& _s)
{
    if ("diamond" == _s) return 0;
    else if ("iron" == _s) return 1;
    else return 2;
}

int solution(vector<int> picks, vector<string> minerals)
{
    vector<int> vp;
    vector<int> vm(minerals.size(), 0);
    int answer = 100000;

    transform(minerals.begin(), minerals.end(), vm.begin(), convert);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < picks[i]; ++j) vp.push_back(i);

    do
    {
        int m = min(vp.size() * 5, vm.size());
        int s = 0;

        for (int i = 0; i < m; ++i)
        {
            int t = vm[i] - vp[i / 5];
            if (t == -2) s += 25;
            else if (t == -1) s += 5;
            else s += 1;
        }

        answer = min(answer, s);
    } while (next_permutation(vp.begin(), vp.end()));

    return answer;
}