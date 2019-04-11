#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
const int N = 50005, M = 1250000;
int head[N], nxt[M], to[M], vis[N], vid = 1, ne, n, m, caseCounter;

void init()
{
	memset(head, -1, sizeof head);
	ne = 0;
}

void addEdge(int u, int v)
{
	to[ne] = v;
	nxt[ne] = head[u];
	head[u] = ne;
	++ne;
}

void addBiEdge(int u, int v)
{
	addEdge(u, v);
	addEdge(v, u);
}

void dfs(int u)
{
	if (vis[u] == vid) return;
	vis[u] = vid;
	for (int k = head[u]; k != -1; k = nxt[k])
	{
		int v = to[k];
		dfs(v);
	}
}

int main()
{

	while (scanf("%d %d", &n, &m), n != 0 || m != 0)
	{
		int u, v;
		init();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			addBiEdge(u, v);
		}
		int compCounter = 0;
		for (int i = 0; i < n; ++i)
		{
			if (vis[i] != vid)
			{
				dfs(i);
				++compCounter;
			}
		}
		++vid;
		printf("Case %d: %d\n",++caseCounter, compCounter);
	}

	return 0;
}