#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int n;
vector<string> grid;
const int N = 100 + 5;
int visited[N][N];
int vid;
int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1, 0, 0 };
int cases;
void bfs(pair<int, int> source)
{
	queue<pair<int, int>> q;
	q.push(source);
	visited[source.first][source.second] = vid;
	while (!q.empty())
	{
		auto u = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> dest(u.first + x[i], u.second + y[i]);
			if (dest.first >= 0 && dest.first < n && dest.second >= 0 && dest.second < n
				&& visited[dest.first][dest.second] != vid
				&& (grid[dest.first][dest.second] == 'x' || grid[dest.first][dest.second] == '@'))
			{
				q.push(dest);
				visited[dest.first][dest.second] = vid;
			}
		}
	}
}
int main()
{
	char buffer[N];
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		string temp;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", buffer);
			temp = buffer;
			grid.push_back(temp);
		}
		++vid;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (visited[i][j] != vid && grid[i][j] == 'x')
				{
					bfs({ i,j });
					cnt++;
				}
		printf("Case %d: %d\n", ++cases, cnt);
		grid.clear();
	}
	return 0;
}