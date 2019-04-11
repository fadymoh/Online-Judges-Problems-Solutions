#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 50 + 5, M = 2e3 + 10;
vector<vector<pair<int, int>>> adj;// first child, second edge ID
int vis[M];
int vid;
int caseCounter;
vector<int> res;
void euler(int u) {
	while (adj[u].size()) {
		auto cur = adj[u].back();
		adj[u].pop_back();
		if (vis[cur.second] == vid)
			continue;
		vis[cur.second] = vid;
		printf("%d %d\n", u + 1, cur.first + 1);
		euler(cur.first);
		//printf("%d %d\n", u, cur.first);
	}
	res.push_back(u);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for(int t = 0; t < tc; ++t)
	{
		if (t) puts("");		
		printf("Case #%d\n", ++caseCounter);

		int n;
		++vid;
		scanf("%d", &n);
		int u, v;
		adj = vector<vector<pair<int, int>>>(N + 5);
		int st = 1e9;
		bool isOdd[N];
		memset(isOdd, 0, sizeof isOdd);
		res = vector<int>(N+ 5);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			adj[u].push_back({ v, i });
			adj[v].push_back({ u, i });
			isOdd[u] ^= 1;
			isOdd[v] ^= 1;
			st = min(st, min(u, v));
		}

		//for (auto &v : adj)
		//	sort(v.rbegin(), v.rend());
		int idx = find(isOdd, isOdd + N, 1) - isOdd;
		if (idx != N)
			st = idx;
		bool ok = true;
		ok &= count(isOdd, isOdd + N, 1) == 0; // not required for this problem
		if (!ok)
			puts("some beads may be lost");
		else
			euler(st);
	}
	

	return 0;
}