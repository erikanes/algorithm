#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string name;
    int start;
    int playtime;
};

int to_time(const string& _s)
{
    return (_s[0] - '0') * 600 + (_s[1] - '0') * 60 + (_s[3] - '0') * 10 + (_s[4] - '0');
}

Node nodes[1001];

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<int> s;
    int n = plans.size();

    for (size_t i = 0; i < n; ++i)
    {
        nodes[i].name = move(plans[i][0]);
        nodes[i].start = to_time(plans[i][1]);
        nodes[i].playtime = stoi(plans[i][2]);
    }

    sort(nodes, nodes + n, [](const Node& a, const Node& b) { return a.start < b.start; });

    int idx = 0;
    int cur = 0;
    int next = idx++;

    while (idx < n)
    {
        cur = next;
        next = idx++;

        int diff = nodes[next].start - nodes[cur].start;

        if (diff >= nodes[cur].playtime)
        {
            diff -= nodes[cur].playtime;
            answer.push_back(nodes[cur].name);

            while (diff > 0 && !s.empty())
            {
                int t = s.top(); s.pop();

                if (diff >= nodes[t].playtime)
                {
                    diff -= nodes[t].playtime;
                    answer.push_back(nodes[t].name);
                }

                else
                {
                    nodes[t].playtime -= diff;
                    diff = 0;
                    s.push(t);
                }
            }
        }

        else
        {
            nodes[cur].playtime -= diff;
            s.push(cur);
        }
    }

    answer.push_back(nodes[n - 1].name);

    while (!s.empty())
    {
        int t = s.top(); s.pop();
        answer.push_back(nodes[t].name);
    }

    return answer;
}