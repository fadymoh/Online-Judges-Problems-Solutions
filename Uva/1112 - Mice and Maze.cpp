#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <numeric>
using namespace std;
const int N = 100 + 5;
int mat[N][N], dist[N], notVisited[N];

void shortestPath(int src) {
	memset(dist, 0x3f, sizeof dist);
	iota(notVisited, notVisited + N, 0);
	dist[src] = 0;
	int sz = N, nxt = src;
	do {
		int u = notVisited[nxt];
		notVisited[nxt] = notVisited[--sz];
		int best = 0x3f3f3f3f;
		nxt = -1;
		for (int k = 0; k < sz; ++k) {
			int v = notVisited[k];
			int d = dist[u] + mat[u][v];
			if (dist[v] > d)
				dist[v] = d;
			if (best > dist[v]) {
				best = dist[v];
				nxt = k;
			}
		}
	} while (nxt != -1);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, e, t, m;
		scanf("%d", &n); scanf("%d", &e); scanf("%d", &t); scanf("%d", &m);
		memset(mat, 0x3f, sizeof mat);
		for (int i = 0; i < m; ++i)
		{
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c); --u; --v;
			mat[u][v] = mat[v][u] = min(mat[v][u], c);
		}
		shortestPath(e-1);
		int escaped = 0;
		for (int i = 0; i < n; ++i)
		{
			if (dist[i] <= t)
				++escaped;
		}
		printf("%d\n", escaped);
		if (tc) puts("");
	}

	return 0;
}
