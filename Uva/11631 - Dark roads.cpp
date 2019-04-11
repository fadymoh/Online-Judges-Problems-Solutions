#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;

const int N = 1e4 + 5, M = 1e4 + 6, QS = 1024, QS1 = 1023, OO = 0x3f3f3f3f;
int x[N], y[N];
double trains, roads;
int states;
int parent[N], sz[N], comps, n, m, r;

void init() {
	comps = n;
	iota(parent, parent + n, 0);
	fill(sz, sz + n, 1);
}

int frm[M], to[M], sorted[M];
double cost[M];

int find(int u) {
	return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)  return 0;
	if (sz[u] > sz[v]) swap(u, v);
	parent[u] = v;
	sz[v] += sz[u];
	--comps;
	return 1;
}

int kruskal() {
	int ret = 0;
	sort(sorted, sorted + m, [](int a, int b) {
		return cost[a] < cost[b];
	});
	trains = roads = states = 0;
	for (int i = 0; i < m; ++i) {
		int idx = sorted[i];
		if (merge(frm[idx], to[idx])) 
		{
			double d = cost[idx];
			cout << d << endl;
			if (d > r)
			{
				trains += d;
				++states;
			}
			else 
				roads += d;
		}
	}
	return ret;
}
void calculateDistance()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			double distance = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			frm[m] = i;
			to[m] = j;
			cost[m] = sqrt(distance);
			sorted[m] = m++;
		}
	}
}
int main()
{

	int tc;
	scanf("%d", &tc);
	int caseCounter = 0;
	while (tc--)
	{
	
		scanf("%d %d", &n, &r);
		init();
		for (int i = 0; i < n; ++i) 
			scanf("%d %d", x + i, y + i);
		m = 0;
		calculateDistance();
		kruskal();
		printf("Case #%d: %d %d %d\n", ++caseCounter, states + 1, (int)roads, (int)trains);
	}
	return 0;
}