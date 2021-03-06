#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 2000 + 3;
int dfsT[N], lo[N], curT;
vector<vector<int>> adj;
stack<int> stk;
int cmpID[N], nc;

void tarjanDFS(int u) {
	dfsT[u] = lo[u] = curT++;
	stk.push(u);
	for (auto v : adj[u]) {
		if (dfsT[v] == -1) {
			tarjanDFS(v);
			lo[u] = min(lo[u], lo[v]);
		}
		else if (cmpID[v] == -1) {
			lo[u] = min(lo[u], lo[v]);
		}
	}
	if (lo[u] == dfsT[u]) { // u root component
		int x;
		do {
			x = stk.top();
			stk.pop();
			cmpID[x] = nc;
		} while (x != u);
		++nc;
	}
}

void tarjan() {
	memset(dfsT, -1, adj.size() * sizeof dfsT[0]);
	memset(cmpID, -1, adj.size() * sizeof cmpID[0]);
	for (int i = 0; i < adj.size(); ++i) {
		if (dfsT[i] == -1)
			tarjanDFS(i);
	}
}

int main()
{
	int n, m, u, v, type;

	while (scanf("%d %d", &n, &m), n != 0 || m != 0)
	{
		nc = 0;
		adj = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &type); --u, --v;
			adj[u].push_back(v);
			if (type == 2)
				adj[v].push_back(u);
		}
		tarjan();

		printf("%d\n", nc == 1);
	}

	return 0;
}