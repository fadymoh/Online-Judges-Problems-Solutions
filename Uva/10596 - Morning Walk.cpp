#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3 + 3, M = 1e3 + 3;
vector<vector<pair<int, int>>> adj;// first child, second edge ID
int vid, vis[M];
int n, m;
int myCount;
void euler(int u) {
	while (adj[u].size()) {
		auto cur = adj[u].back();
		adj[u].pop_back();
		if (vis[cur.second] == vid)
			continue;
		vis[cur.second] = vid;
		euler(cur.first);
	}
	++myCount;
}
void dfs(int u)
{
	vis[u] = 1;
	for (auto v : adj[u])
	{
		if (vis[v.first] == 1)
			continue;
		dfs(v.first);
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		int u, v;
		adj = vector<vector<pair<int, int>>>(N + 1);
		++vid;
		bool isOdd[N];
		memset(vis, -1, sizeof vis);
		memset(isOdd, 0, sizeof isOdd);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back({ v, i });
			adj[v].push_back({ u, i });
			isOdd[u] ^= 1;
			isOdd[v] ^= 1;
			vis[u] = 0; vis[v] = 0;
		}
		bool ok = true;
		ok &= count(isOdd, isOdd + N, 1) <= 0; // not required for this problem
		myCount = 0;
		if (ok)
		{
			for (int i = 0; i < n && myCount <= 1; ++i)
				if (vis[i] == 0) 
					dfs(i), ++myCount;

			ok &= myCount == 1;
		}
		if (ok) puts("Possible");
		else puts("Not Possible");
	}

	return 0;
}