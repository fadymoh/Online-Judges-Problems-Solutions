#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
vector< vector<int> > adj;
int dst[100005];
int n, m;
const int N = 2500 + 3;
int globalMax = 0, globalIndex = 0;
int maxLevel = 0;
bool visited[N];
void bfs(int source) {
	memset(dst, -1, sizeof dst);
	memset(visited, 0, sizeof visited);
	queue<int> q;
	q.push(source);
	dst[source] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int ng : adj[cur]) {
			if (dst[ng] == -1) {
				dst[ng] = dst[cur] + 1;
				q.push(ng);
				maxLevel = max(maxLevel, dst[ng]); 
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	adj = vector<vector<int>>(N);
	for (int u = 0; u < n; ++u)
	{
		int noFriends;
		scanf("%d", &noFriends);
		for (int j = 0; j < noFriends; ++j)
		{
			int v;
			scanf("%d", &v);
			adj[u].push_back(v);
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int source;
		scanf("%d", &source);
		maxLevel = 0;
		bfs(source);
		globalIndex = globalMax = 0;
		for (int i = 1; i <= maxLevel; ++i)
		{
			int noElements = count(dst, dst + n, i);
			if (noElements > globalMax) {
				globalIndex = i;
				globalMax = noElements;
			}
		}
		if (!globalMax) puts("0");
		else printf("%d %d\n", globalMax, globalIndex);
	}

	return 0;
}