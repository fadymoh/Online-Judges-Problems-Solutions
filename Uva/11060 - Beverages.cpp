#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <functional>   // std::greater

using namespace std;
const int N = 100 + 10;
int n, m;
string myNodes[N];
char buffer[100];
int caseCounter;
int main()
{
	char name[N][N];
	while (scanf("%d", &n) == 1)
	{
		unordered_map<string, int> mapping;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", name[i]);
			mapping[name[i]] = i;
		}
		scanf("%d", &m);
		int u, v;
		vector<int> adj[N];
		int in[N] = {};
		for (int i = 0; i < m; ++i)
		{
			scanf("%s", buffer); u = mapping[buffer];
			scanf("%s", buffer); v = mapping[buffer];
			adj[u].push_back(v);
			++in[v];
		}
		priority_queue<int, vector<int>, greater<int> > q;
		for (int node = 0; node < n; ++node)
			if (in[node] == 0)
				q.push(node);

		vector<int> order;
		cout << "Case #" << ++caseCounter << ": Dilbert should drink beverages in this order:";
		while (q.size()) {
			int cur = q.top();
			q.pop();
			order.push_back(cur);
			for (auto child : adj[cur]) {
				in[child]--;
				if (in[child] == 0)
					q.push(child);
			}
			cout << ' ' << name[cur];
		}
		puts(".\n");
	}
	return 0;
}