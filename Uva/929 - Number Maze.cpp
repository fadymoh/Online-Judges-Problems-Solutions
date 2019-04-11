#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 1000;
int dist[N][N];
int n, m;
int mat[N][N];
bool validPos(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}
int posX[4] = { -1,0, 1, 0  };
int posY[4] = { 0 ,1, 0, -1 };
void shortestPath(pair<int, int> src) {
	memset(dist, 0x3f, sizeof dist);
	dist[src.first][src.second] = mat[src.first][src.second];
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[src.first][src.second], src });
	while (pq.size()) {
		int d = -pq.top().first;
		int uX = pq.top().second.first;
		int uY = pq.top().second.second;
		pq.pop();
		if (d != dist[uX][uY]) 
			continue;
		for (int i = 0; i < 4; ++i){
			int xPos = uX + posX[i];
			int yPos = uY + posY[i];
			if (validPos(xPos, yPos))
			{
				int newD = d + mat[xPos][yPos];
				if (dist[xPos][yPos] > newD) {
					dist[xPos][yPos] = newD;
					pq.push({ -newD, {xPos, yPos} });
				}
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
		int cst;
		scanf("%d", &n);
		scanf("%d", &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &mat[i][j]);
		shortestPath({0,0});
		printf("%d\n", dist[n-1][m-1]);
	}
	return 0;
}
