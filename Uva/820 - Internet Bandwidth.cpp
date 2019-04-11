#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e4 + 3, M = 2e4 + 3;
int head[N], nxt[M], to[M], cap[M], ne, n, m, src, snk;

void init()
{
	memset(head, -1, n * sizeof head[0]);
	ne = 0;
}

void addEdge(int u, int v, int c)
{
	to[ne] = v;
	cap[ne] = c;
	nxt[ne] = head[u];
	head[u] = ne;
	++ne;
}

void addAugEdge(int u, int v, int c)
{
	addEdge(u, v, c);
	addEdge(v, u, 0);
}

int vis[N], visID;

int dfs(int u, int minCap)
{
	if (u == snk || minCap == 0) return minCap;
	if (vis[u] == visID) return 0;
	vis[u] = visID;
	for (int k = head[u]; k != -1; k = nxt[k])
	{
		int v = to[k];
		int c = dfs(v, min(minCap, cap[k]));
		if (c)
		{
			cap[k] -= c;
			cap[k ^ 1] += c;
			return c;
		}
	}
	return 0;
}

int maxFlow()
{
	int flow = 0, ret = 0;
	do
	{
		++visID;
		flow = dfs(src, 1e9);
		ret += flow;
	} while (flow);
	return ret;
}
int main()
{
	int caseCounter = 0;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		scanf("%d %d %d", &src, &snk, &m);
		init();
		int u, v, c;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);
			addAugEdge(--u, --v, c);
			addAugEdge(v, u, c);
		}
		--src; --snk;
		printf("Network %d\nThe bandwidth is %d.\n\n", ++caseCounter, maxFlow());
	}


	return 0;
}