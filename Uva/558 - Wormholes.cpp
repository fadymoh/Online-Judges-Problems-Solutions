#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define N 3000
int pre[N];
int n, m;
int frm[N], to[N], cst[N];
int dst[N];

bool bellmanford(int src) {
	memset(dst, '?', sizeof(dst));
	dst[src] = 0;

	bool edit = true;
	for (int i = 0; i <= m && edit; i++) {
		edit = false;
		for (int j = 0; j < m; j++) {
			if (dst[to[j]] > dst[frm[j]] + cst[j]) {
				edit = true;
				dst[to[j]] = dst[frm[j]] + cst[j];
			}
		}
	}

	return edit; // returns true if there's a negative cycle
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &frm[i], &to[i], &cst[i]);
		}
		if (bellmanford(0)) puts("possible");
		else puts("not possible");
	}

	return 0;
}