#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int N = 128 + 3;
string names[N];
char buffer[N];
vector<int> adj[N];
vector<int> order;
int in[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", buffer);
		names[i] = buffer;
	}
	// name1 < name2 < name3...
	for (int i = 0; i < n - 1; ++i)
	{
		int j = 0;
		while (j < names[i].length() && j < names[i + 1].length() && names[i][j] == names[i + 1][j]) ++j;
		//s is a prefix of t
		if (j == names[i + 1].length()) { printf("Impossible\n");  return 0; }
		if (j < names[i].length() && j < names[i+1].length())
		{
			adj[names[i][j]].push_back(names[i + 1][j]);
			++in[names[i + 1][j]];
		}
	}
	// topological order using bfs
	queue<int> q;
	for (int node = 'a'; node <= 'z'; ++node)
		// the first vertex in topological sorting is always a vertex with in-degree 0
		if (in[node] == 0)
			q.push(node);

	vector<int> order;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		order.push_back(cur);
		for (auto child : adj[cur]) {
			in[child]--;
			if (in[child] == 0)
				q.push(child);
		}
	}
	if (order.size() == 26)
		for (int i = 25; i >= 0; --i) printf("%c", order[25-i], "\n."[!!i]);
	else printf("Impossible\n");
	return 0;
}