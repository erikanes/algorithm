#include <bits/stdc++.h>

using namespace std;

int indegree[1000001];
int outdegree[1000001];

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0);

    for (const auto& edge : edges)
        ++indegree[edge[1]], ++outdegree[edge[0]];

    for (int i = 1; i <= 1000000; ++i)
    {
        if (0 == indegree[i] && 2 <= outdegree[i]) answer[0] = i;
        else if (1 <= indegree[i] && 0 == outdegree[i]) ++answer[2];
        else if (2 <= indegree[i] && 2 == outdegree[i]) ++answer[3];
    }

    answer[1] = outdegree[answer[0]] - (answer[2] + answer[3]);

    return answer;
}