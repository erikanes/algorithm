#include <bits/stdc++.h>
using namespace std;

int dist[100001];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	queue<int> q;
	int n, k;

	cin >> n >> k;

	dist[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			cout << dist[cur];
			return 0;
		}

		for (auto nxt : {cur*2, cur-1, cur+1})
		{
			if (nxt < 0 || nxt > 100000)
				continue;
            
			if (dist[nxt])
				continue;
            
            if (nxt == cur*2)
                dist[nxt] = dist[cur];
            else
			    dist[nxt] = dist[cur]+1;
            
			q.push(nxt);
		}
	}

	return 0;
}