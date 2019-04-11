#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 2*40000 + 10, M = 2*40000 + 7;
int *head, to[M], nxt[M];
int headG[N], headk[N];
int ne, n;

void init()
{
	head = headG;
	memset(head, -1, n * sizeof head[0]);
	memset(headk, -1, n * sizeof headk[0]);
	ne = 0;
}
void addEdge(int f, int t)
{
	to[ne] = t;
	nxt[ne] = head[f];
	head[f] = ne++;
}

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)

int tim[N], lo[N], cmp[N], curT, cmpSz;
int stk[N], stkSz;

void tarjanDFS(int u)
{
	tim[u] = lo[u] = curT++;
	stk[stkSz++] = u;
	for (int e = head[u]; ~e; e = nxt[e])
	{
		int v = to[e];
		if (tim[v] == -1)
		{
			tarjanDFS(v);
			lo[u] = min(lo[u], lo[v]);
		} else if (cmp[v] == -1) 
			lo[u] = min(lo[u], lo[v]);
	}
	if (tim[u] == lo[u])
	{
		do {
			cmp[stk[--stkSz]] = cmpSz;
		} while (stk[stkSz] != u);
		cmpSz++;
	}
}

void StronglyConnectedComponents()
{
	curT = cmpSz = 0;
	memset(cmp, -1, n * sizeof cmp[0]);
	memset(tim, -1, n * sizeof tim[0]);
	for (int u = 0; u < n; ++u)
	{
		if (cmp[u] == -1)
			tarjanDFS(u);
	}
}

int cmpVal[N];
bool TwoSat()
{
	StronglyConnectedComponents();
	for (int u = 0; u < n; ++u)
	{
		if (cmp[u] == cmp[NOT(u)])
			return false;
	}
	return true;
}
void addOR(int u, int v)
{
	addEdge(NOT(u), v);
	addEdge(NOT(v), u);
}
void addXOR(int u, int v)
{
	addOR(u, v);
	addOR(NOT(u), NOT(v));
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int m, l;
		scanf("%d %d %d", &n, &m, &l);
		n *= 2;
		init();
		int u, v;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			u = VAR(u);
			v = VAR(v);
			addOR(u, v);
		}
		for (int i = 0; i < l; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			u = VAR(u);
			v = VAR(v);
			addXOR(u, v);
		}
		if (TwoSat()) puts("YES");
		else puts("NO");
	}
	return 0;
}
