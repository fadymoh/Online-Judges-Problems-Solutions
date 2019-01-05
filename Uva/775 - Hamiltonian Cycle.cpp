#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
vector <vector<int>> graph;//A c
						   //[1 0 1 1] B
bool visited[257];
char line[100];
vector<int> solution;
int n, a, b;
bool check_if_end(int node)
{
	for (int i = 0; i < graph[node].size(); ++i)
		if (graph[node][i] == 0) return true;
	return false;
}
bool backtrack(int node, int count)
{
	visited[node] = true;
	solution.push_back(node);
	if (count == n - 1 && check_if_end(node))
	{
		for (int i = 0; i < solution.size(); ++i)
				cout << solution[i] + 1 << ' ';
		cout << 1 << endl;
		return true;
	}
	for (int i = 0; i < graph[node].size(); ++i)
	{
		if (!visited[graph[node][i]])
		{
			if (backtrack(graph[node][i], count + 1))
				return true;
		}
	}
	solution.pop_back();
	visited[node] = false;
	return false;
}
int main()
{
	while (true)
	{
		if (scanf("%d\n", &n) == -1) break;
		graph.assign(n, vector<int>());
		for (int i = 0; i < n; ++i) visited[i] = false;
		solution.clear();
		while (gets_s(line), strcmp(line, "%")) {
			sscanf(line, "%d %d", &a, &b);
			graph[a - 1].push_back(b - 1); graph[b - 1].push_back(a - 1);
		}
		if (!backtrack(0, 0))
			cout << "N\n";
	}
	system("pause");
	return 0;
}