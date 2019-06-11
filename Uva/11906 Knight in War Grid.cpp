#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int R = 100 + 3;
const int C = 100 + 3;
int grid[R][C];
int visited[R][C];
int vid;
int r, c, m, n, w;
int x[8];
int y[8];
set<pair<int, int>> water;
bool withinGrid(pair<int, int> curr, pair<int, int> dest, pair<int, int> &loc)
{
	int xdelta = curr.first + dest.first;
	int ydelta = curr.second + dest.second;
	loc = { xdelta, ydelta };
	return ((xdelta < r) && (ydelta < c) && (xdelta >= 0) && (ydelta >= 0));
}
void bfs(pair<int,int> source)
{
	queue<pair<int, int>> q;
	q.push(source);
	visited[0][0] = vid;
	while (!q.empty())
	{
		auto u = q.front(); q.pop();
		set<pair<int, int>> children;
		for (int i = 0; i < 8; ++i)
		{
			pair <int, int> loc;
			if (withinGrid(u, { x[i], y[i] }, loc) && water.find(loc) == water.end())
				children.insert(loc);
		}

		for (auto &loc: children)
		{
			++grid[loc.first][loc.second];
			if (visited[loc.first][loc.second] != vid)
			{
				visited[loc.first][loc.second] = vid;
				q.push(loc);
			}
		}
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	int cases = 0;
	while (tc--)
	{
		scanf("%d %d %d %d", &r, &c, &m, &n);
		scanf("%d", &w);
		int u, v;
		++vid;
		for (int i = 0; i < w; ++i)
		{
			scanf("%d %d", &u, &v);
			water.insert({u, v});
		}
		x[0] = m; x[1] = n; x[2] = -m; x[3] = -n; x[4] = m; x[5] = -n; x[6] = -m; x[7] = n;
		y[0] = n; y[1] = m; y[2] = -n; y[3] = -m; y[4] = -n; y[5] = m; y[6] = n; y[7] = -m;
		bfs({0,0});
		int even = 0, odd = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if ((!i && !j) || grid[i][j])
				{
					if (grid[i][j] & 1) ++odd;
					else ++even;
				}
			}
		}
		printf("Case %d: %d %d\n", ++cases, even, odd);
		memset(grid, 0, sizeof grid);
		water.clear();
	}
	return 0;
}