#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 3, M = 1e5 + 3;
vector<vector<pair<int, int>>> adj;
int vis[M];
int vid;
bool isOdd[N];
vector<pair<int, int>> res;
int tc, n;

void euler(int u)
{
	while (adj[u].size())
	{
		auto curr = adj[u].back();
		adj[u].pop_back();
		if (vis[curr.second] == vid) continue;
		vis[curr.second] = vid;
		euler(curr.first);
		res.push_back({ u + 1, curr.first + 1 });
		//do some processing
	}
}


int main()
{
	scanf("%d", &tc);
	int caseCounter = 0;
	for (int i = 0; i < tc; ++i)
	{
		if (i) puts("");
		printf("Case #%d\n", ++caseCounter);
		scanf("%d", &n);
		int u, v;
		++vid;
		adj = vector<vector<pair<int, int>>>(N+1);
		res.clear();
		int st = 1e9;
		memset(isOdd, 0, sizeof isOdd);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &u, &v); --u, --v;
			adj[u].push_back({ v, i });
			adj[v].push_back({ u, i });
			isOdd[u] ^= 1;
			isOdd[v] ^= 1;
			st = min(st, min(u, v));
		}
		bool ok = true;
		int idx = find(isOdd, isOdd + N, 1) - isOdd;
		if (idx != N)
			st = idx;
		ok &= count(isOdd, isOdd + N, 1) == 0;
		euler(st);
		ok &= res.size() == n;
		if (!ok)
			puts("some beads may be lost");
		else
			for (auto p : res)
				printf("%d %d\n", p.second, p.first);
	}
	return 0;
}
