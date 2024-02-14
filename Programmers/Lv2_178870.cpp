#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    const int l = sequence.size();
    int p1 = 0, p2 = 0, sum = sequence[0];
    vector<int> answer(2, 0);
    answer[0] = 0;
    answer[1] = 1000001;

    sequence.push_back(1000001);

    while (p1 <= p2 && p2 < l)
    {
        if (sum == k)
        {
            if (p2 - p1 < answer[1] - answer[0])
                answer[0] = p1, answer[1] = p2;

            sum -= sequence[p1++];
        }

        else if (sum < k)
            sum += sequence[++p2];

        else
            sum -= sequence[p1++];
    }

    return answer;
}