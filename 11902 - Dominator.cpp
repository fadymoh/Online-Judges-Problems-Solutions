#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool graph[101][101];
bool visited[101];
int n;
void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < n; ++i)
		if (graph[node][i] && !visited[i]) dfs(i);
}
void printLineBreak()
{
	cout << '+';
	for (int i = 0; i < n * 2 - 1; ++i)
		cout << '-';
	cout << "+\n";
}
int main()
{
	int tc, case_counter = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> graph[i][j];
		bool dominatedGraph[101][101];
		memset(dominatedGraph, 0, sizeof dominatedGraph);
		dominatedGraph[0][0] = true;
		for (int i = 1; i < n; ++i)
		{
			dominatedGraph[0][i] = true;
			memset(visited, 0, sizeof visited);
			visited[i] = true;
			dfs(0);
			for (int j = 0; j < n; ++j)
				if (!visited[j]) dominatedGraph[i][j] = true;
			dominatedGraph[i][i] = true;
		}
		memset(visited, 0, sizeof visited);
		dfs(0);
		cout << "Case " << ++case_counter << ":\n";
		printLineBreak();
		for (int i = 0; i < n; ++i) 
		{
			for (int j = 0; j < n; ++j)
				cout << ((dominatedGraph[i][j] && visited[j]) ? "|Y" : "|N");
			cout << "|\n";
			printLineBreak();
		}
	}
	return 0;
}