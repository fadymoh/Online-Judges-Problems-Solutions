#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
int n, r;
typedef long long ll;

const int N = 1e2 + 5, M = 1e4 + 6, QS = 1024, QS1 = 1023, OO = 0x3f3f3f3f;

int m, roads, states, trains;
int x[N], y[N];
int head[N], nxt[2 * M], to[2 * M], ne;
double cost[2 * M];
double dist[N];
int caseCounter;
void init()
{
	ne = 0;
	memset(head, -1, n * sizeof head[0]);
}
void addEdge(int f, int t, double c)
{
	to[ne] = t;
	nxt[ne] = head[f];
	cost[ne] = c;
	head[f] = ne++;
}
void addBiEdge(int a, int b, double c)
{
	addEdge(a, b, c);
	addEdge(b, a, c);
}

int vis[N], vid;
int prim(int src) {
	int res = 0;
	++vid;
	memset(dist, 1e9, n * sizeof dist[0]);
	dist[src] = 0;
	vis[src] = vid;
	priority_queue<pair<double, int> >q;
	q.push({ 0,src });
	roads = states = trains = 0;
	while (q.size()) {
		int u = q.top().second;
		double d = -q.top().first;
		q.pop();
		if (!(dist[u] - d < 1e-9))
			continue;
		res += d;
		if (d > r) roads += d;
		else
		{
			trains += d;
			++states;
		}
		vis[u] = vid;
		for (int k = head[u]; ~k; k = nxt[k]) {
			int v = to[k];
			if (vis[v] == vid) continue;
			double nd = cost[k];
			if (dist[v] - nd > 1e-9) {
				dist[v] = nd;
				q.push({ -nd,v });
			}
		}
	}
	return res;
}
void calculateDistance()
{
	for (int i = 0; i < n; ++i)
	{
		addEdge(i, i, 0);
		for (int j = 0; j < i; ++j)
		{
			double distance = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			++m;
			addBiEdge(i, j, sqrt(distance));
		}
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		init();
		scanf("%d %d", &n, &r);
		for (int i = 0; i < n; ++i) scanf("%d %d", x + i, y +  i);
		m = 0;
		calculateDistance();
		prim(0);
		printf("Case #%d: %d %0.1f %0.1f\n", ++caseCounter, states, roads, trains);
	}
	return 0;
}
