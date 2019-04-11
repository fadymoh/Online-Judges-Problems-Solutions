#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;
int cost, r, q;
const int N = 1e5 + 5;
int pre[N];
int n, m;
int frm[N], to[N], cst[N];
long long dst[N];
int caseCounter = 0;
bool bellmanford(int src) {
	fill(dst, dst + N, INT_MAX);
	dst[src] = 0;

	bool edit = true;
	for (int i = 0; i <= n - 1 && edit; i++) {
		edit = false;
		for (int j = 0; j < m; j++) {
			if (dst[to[j]] > dst[frm[j]] + cst[j] && dst[frm[j]] != INT_MAX) {
				edit = true;
				dst[to[j]] = dst[frm[j]] + cst[j];
			}
		}
	}

	return edit; // returns true if there's a negative cycle
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		vector<int> busy(n);
		for (int i = 0; i < n; ++i) scanf("%d", &busy[i]);
		scanf("%d", &m);
		int u, v;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v); --u; --v;
			frm[i] = u;
			to[i] = v;
			int diff = busy[to[i]] - busy[frm[i]];
			cst[i] = diff * diff * diff;
		}
		scanf("%d", &q);
		int source;
		printf("Set #%d\n", ++caseCounter);
		bellmanford(0);

		for (int j = 0; j < m; j++) {
			if (dst[to[j]] > dst[frm[j]] + cst[j] && dst[frm[j]] != INT_MAX) {
				dst[to[j]] = -INT_MIN;

			}
		}
		for (int i = 0; i < q; ++i)
		{
			scanf("%d", &source);
			--source;
			if (dst[source] < 3 || dst[source] == INT_MAX) puts("?");
			else printf("%d\n", dst[source]);
		}
	}
	return 0;
}