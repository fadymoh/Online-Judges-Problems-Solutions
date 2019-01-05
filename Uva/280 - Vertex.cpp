#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> AdjacencyList;
bool visited[101];
int n;

void bfs(int source)
{
	memset(visited, 0, sizeof visited);
	queue<int> q;
	q.push(source);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < AdjacencyList[u].size(); ++i)
		{
			int v = AdjacencyList[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
	int arr[101];
	int counter = 0;
	for (int i = 0; i < n; ++i)
		if (!visited[i]) arr[counter++] = i;
	cout << counter;
	for (int i = 0; i < counter; ++i)
		cout << ' ' << arr[i] + 1;
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n, n != 0)
	{
		AdjacencyList.clear();
		AdjacencyList.resize(n);

		int startVertex;
		while (cin >> startVertex, startVertex != 0)
		{
			int node;
			while (cin >> node, node != 0)
				AdjacencyList[startVertex - 1].push_back(node - 1);
		}
		int count, temp;
		cin >> count;
		for (int i = 0; i < count; ++i)
		{
			cin >> temp;
			bfs(temp - 1);
		}
	}
	return 0;
}