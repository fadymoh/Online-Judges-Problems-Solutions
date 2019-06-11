#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> adjacencyList;
const int N = 1e8;
int visited[N];
int vid;
int n;
void dfs(int node)
{
	visited[node] = vid;
	for (int child : adjacencyList[node])
	{
		if (visited[child] != vid)
			dfs(child);
	}
}
int main()
{
	int tc;
	scanf("%d\n\n", &tc);
	string buffer;
	while (tc--)
	{
		getline(cin, buffer);
		adjacencyList.clear();
		n = buffer[0] - 'A' + 1;
		adjacencyList.resize(n + 1);
		while (1)
		{
			if (!getline(cin, buffer) || buffer.empty()) break;
			int u = buffer[0] - 'A', v = buffer[1] - 'A';
			adjacencyList[u].push_back(v);
			adjacencyList[v].push_back(u);
		}
		int ans = 0;
		++vid;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i] != vid)
			{
				++ans;
				dfs(i);
			}
		}
		printf("%d\n", ans);
		if (tc) puts("");
	}
	return 0;
}