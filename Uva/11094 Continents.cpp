#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
vector<string> grid;
const int N = 20 + 2;
const int M = 20 + 3;
int visited[N][M];
int ans;
int vid;
int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1, 0, 0 };
char land;
void bfs(pair<int, int> source)
{
	queue<pair<int, int>> q;
	q.push(source);
	visited[source.first][source.second] = vid;
	while (!q.empty())
	{
		auto u = q.front(); q.pop();
		++ans;
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> dest(u.first + x[i], u.second + y[i]);
			
			if (dest.second == m) dest.second = 0;
			if (dest.second == -1) dest.second = m - 1;
			if (dest.first >= 0 && dest.first < n && visited[dest.first][dest.second] != vid && grid[dest.first][dest.second] == land)
			{
				q.push(dest);
				visited[dest.first][dest.second] = vid;
			}
		}
	}
}
int main()
{
	char buffer[M];
	while (scanf("%d %d", &n, &m) == 2)
	{
		string temp;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", buffer);
			temp = buffer;
			grid.push_back(temp);
		}
		pair<int, int> source;
		scanf("%d %d", &source.first, &source.second);
		land = grid[source.first][source.second];
		++vid;
		bfs(source);
		int mxAns = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j] != vid && grid[i][j] == land)
				{
					ans = 0;
					bfs({ i,j });
					mxAns = max(mxAns, ans);
				}
			}
		}
		printf("%d\n", mxAns);
		grid.clear();
	}


	return 0;
}