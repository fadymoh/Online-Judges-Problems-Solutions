#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 3;
vector<vector<int>> adj;
int in[N];
int n, m;
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &m);
		int u, v;
		adj = vector<vector<int>>(n);
		memset(in, 0, sizeof in);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			adj[u].push_back(v);
			++in[v];
		}
		queue<int> q;
		for (int node = 0; node < n; ++node)
			if (in[node] == 0)
				q.push(node);
		vector<int> order;
		if (q.size() == 0)
			printf("%d\n", -1);
		else
		{
			while (q.size())
			{
				int cur = q.front();
				q.pop();
				order.push_back(cur);
				for (auto child : adj[cur])
				{
					in[child]--;
					if (in[child] == 0)
						q.push(child);
				}
			}
			int sz = order.size();
			if (sz != n)
				puts("-1");
			else
			for (int i = 0; i < sz; ++i)
			{
				printf("%d%c", order[i] + 1, " \n"[!!(i == sz - 1)]);
			}
		}
	}
	return 0;
}