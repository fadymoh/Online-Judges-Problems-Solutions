#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };
const int N = 185;
int mat[N][N];
int n, m;



void bfs(const pair<int, int> &source)
{
	queue<pair<int, int>> myQueue;
	myQueue.push({ source });
	while (myQueue.size())
	{
		auto curr = myQueue.front();
		myQueue.pop();
		int xPos = curr.first;
		int yPos = curr.second;
		int dist = mat[xPos][yPos] + 1;
		for (int i = 0; i < 4; ++i)
		{
			if (xPos + x[i] > 0 && xPos + x[i] <= n && yPos + y[i] > 0 && yPos + y[i] <= m && dist < mat[xPos + x[i]][yPos + y[i]])
			{
				mat[xPos + x[i]][yPos + y[i]] = dist;
				myQueue.push({ xPos + x[i],yPos + y[i] });
			}
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		char in;
		vector<pair<int, int>> sources;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf(" %c", &in);
				if (in == '1')
				{
					sources.push_back({ i, j });
					mat[i][j] = 0;
				}
				else
					mat[i][j] = 0x3f;
			}
		}
		for (int i = 0; i < sources.size(); ++i)
			bfs(sources[i]);

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				printf("%d ", mat[i][j]);
			puts("");
		}
	}

	return 0;
}