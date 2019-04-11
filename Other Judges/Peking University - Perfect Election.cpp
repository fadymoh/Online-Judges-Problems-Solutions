#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e3 + 10, M = 1e7 + 7;
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

void addOr(int u, int v)
{
	addEdge(NOT(u), v);
	addEdge(NOT(v), u);
}

void addXOR(int u, int v)
{
	addOr(u, v);
	addOr(NOT(u), NOT(v));
}

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
		}
		else if (cmp[v] == -1)
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
		if (cmp[u] == cmp[NOT(u)])
			return false;
	return true;
}

int main()
{
	int m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		int u, v;
		char first, second;
		n *= 2;
		init();
		char firstNode[20], secondNode[20];
		for (int i = 0; i < m; ++i)
		{
			scanf(" %c%s %c%s", &first, firstNode, &second, secondNode);
			u = atoi(firstNode) - 1;
			v = atoi(secondNode) - 1;
			u = VAR(u);
			v = VAR(v);
			if (first == '+')
			{
				if (second == '+')
				{
					addEdge(NOT(u), v);
					addEdge(NOT(v), u);
				}
				else
				{
					addEdge(v, u);
					addEdge(NOT(u), NOT(v));
				}
			}
			else
			{
				if (second == '+')
				{
					addEdge(u, v);
					addEdge(NOT(v), NOT(u));
				}
				else
				{
					addEdge(u, NOT(v));
					addEdge(v, NOT(u));
				}
			}
		}
		if (!TwoSat()) puts("0");
		else puts("1");
	}

	return 0;
}