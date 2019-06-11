#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adjacencyList;
const int N = 50000 + 5;
bool visited[N];
vector<int> sum;
int ans = 1;
void dfs(int node)
{
	visited[node] = true;
	for (auto child : adjacencyList[node])
	{
		if (!visited[child])
		{
			++ans;
			dfs(child);
		}
	}
	visited[node] = false;
	sum[node] = ans;
}
int main()
{
	int tc, cases = 0;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, u,v;
		scanf("%d", &n);
		adjacencyList.resize(n+1);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &u, &v);
			adjacencyList[u].push_back(v);
		}
		sum.assign(n + 1, -1);
		int mxSize = 0, idx = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (sum[i] == -1)
			{
				dfs(i);
				sum[i] = ans;
			}
			if (ans > mxSize)
			{
				mxSize = ans;
				idx = i;
			}
			ans = 1;
		}
		printf("Case %d: %d\n", ++cases, idx);
		adjacencyList.clear();
	}

	return 0;
}