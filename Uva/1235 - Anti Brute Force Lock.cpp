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
			ret += cost[idx];
		}
	}
	return ret;
}
int getDiff(string to, string from)
{
	int res = 0;
	for (int i = 0; i < 4; ++i)
	{
		int diff = abs(to[i] - from[i]);
		if (diff > 5) res += abs(diff - 10);
		else res += diff;
	}
	return res;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		init();
		string in[N];
		char buffer[5];
		int minimum = 1e9;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", buffer);
			in[i] = buffer;
			minimum = min(minimum, getDiff("0000", in[i]));
		}
		m = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int csst = getDiff(in[i], in[j]);
				frm[m] = i;
				to[m] = j;
				cost[m] = csst;
				sorted[m] = m++;
			}
		}
		printf("%d\n", minimum + kruskal());
	}

	return 0;
}