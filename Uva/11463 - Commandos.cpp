#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 100 + 5;
int mat[N][N];
int n, m;
int caseCounter;
void shortestPath() {
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);

}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%d", &m);
		int u, v;
		memset(mat, 0x3f, sizeof mat);
		for (int i = 0; i < n; ++i) mat[i][i] = 0;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v);
			mat[u][v] = mat[v][u] = 1;
		}
		int source, destination;
		scanf("%d %d", &source, &destination);
		shortestPath();
		int ans = -1;
		for (int i = 0; i < n; ++i)
			ans = max(ans, mat[source][i] + mat[i][destination]);
		printf("Case %d: %d\n", ++caseCounter, ans);
	}
	return 0;
}
