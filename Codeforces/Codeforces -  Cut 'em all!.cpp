#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
const int N = 1e5 + 5;
int ans;
int dfs(int node, int parent)
{
	int c = 1;
	for (int i = 0; i < graph[node].size(); ++i)
		if (graph[node][i] != parent)
			c += dfs(graph[node][i], node);
	if (!(c & 1)) ++ans;
	return c;
}
int main()
{
	int n, u, v;
	scanf("%d", &n);
	graph.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if (n & 1)
	{
		puts("-1");
		return 0;
	}
	int t = dfs(1, 0);
	printf("%d", ans-1);
	return 0;
}