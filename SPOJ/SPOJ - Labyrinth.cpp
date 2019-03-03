#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int c, r;
int vis[1001][1001];
bool maze[1001][1001];
int vID = 1;
int mxDepth = 0;
int mxDepthX;
int mxDepthY;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void dfs(int row, int col, int depth)
{
	if (row < 0 || col < 0 || row >= r || col >= c || !maze[row][col]) return;
	if (vis[row][col] == vID) return;
	if (depth > mxDepth)
	{
		mxDepth = depth;
		mxDepthX = row;
		mxDepthY = col;
	}
	vis[row][col] = vID;
	for (int i = 0; i < 4; ++i)
	{
		dfs(row + dx[i], col + dy[i], depth + 1);
	}
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> c >> r;
		char temp;
		mxDepth = 0;
		int firstX, firstY;
		bool flag = false;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin >> temp;
				maze[i][j] = (temp == '#') ? 0: 1;
				if (!flag && temp != '#') firstX = i, firstY = j;
			}
		}
		dfs(firstX, firstY, 0);
		++vID;
		dfs(mxDepthX, mxDepthY, 0);
		++vID;
		cout << "Maximum rope length is " << abs(mxDepth) << ".\n";
	}
	return 0;
}