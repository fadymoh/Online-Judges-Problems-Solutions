#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];
bool visited[100001];
vector<vector<int>> adjacencyList;
int minimum = 10000000001;
void dfs(int node)
{
	visited[node] = true;
	minimum = min(minimum, arr[node]);
	for (int i = 0; i < adjacencyList[node].size(); ++i)
	{
		if (!visited[adjacencyList[node][i]]) dfs(adjacencyList[node][i]);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	adjacencyList.resize(n+1);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjacencyList[x - 1].push_back(y - 1);
		adjacencyList[y - 1].push_back(x - 1);
	}
	memset(visited, false, sizeof visited);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		if (visited[i] == false)
		{
			minimum = 10000000001;
			dfs(i);
			sum += minimum;
		}
	cout << sum << endl;
	return 0;
}