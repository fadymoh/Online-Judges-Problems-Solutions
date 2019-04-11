#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 3;
vector<vector<int>> adj;
int in[N];
int n, m;
int main()
{
	while (scanf("%d %d", &n, &m), n != 0 || m != 0)
	{
		int u, v;
		adj = vector<vector<int>>(n+1);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			++in[v];
		}
		queue<int> q;
		for (int node = 1; node <= n; ++node)
			if (in[node] == 0)
				q.push(node);

		vector<int> order;
		while (q.size()) {
			int cur = q.front();
			q.pop();
			order.push_back(cur);
			for (auto child : adj[cur]) {
				in[child]--;
				if (in[child] == 0)
					q.push(child);
			}
		}
		int sz = order.size();
		for (int i = 0; i < sz; ++i)
			printf("%d%c", order[i], " \n"[!!(i == sz-1)]);
	}
	return 0;
}