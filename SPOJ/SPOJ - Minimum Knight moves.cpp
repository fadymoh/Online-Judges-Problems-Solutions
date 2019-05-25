#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
const int N = 10;
int x[10] = { 0,-1,-1,-2,-2,2,2,1,1 };
int y[10] = { 0,-2,2,-1,1,-1,1,-2,2 };
int dist[N][N];
bool visited[N][N];
void bfs(const pair <int, int> &source, const pair <int, int> &destination)
{
	queue <pair<int, int>> q;
	q.push({ source });
	memset(dist, 0x3f, sizeof dist);
	memset(visited, false, sizeof visited);
	dist[source.first][source.second] = 0;
	while (q.size())
	{
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		if (X == destination.first && Y == destination.second) {
			printf("%d\n", dist[X][Y]);
			return;
		}
		int cost = dist[X][Y];
		for (int i = 1; i <= 8; ++i)
		{
			if (X + x[i] > 0 && X + x[i] <= 8 && Y + y[i] > 0 && Y + y[i] <= 8 && !visited[X + x[i]][Y + y[i]])
			{
				visited[X + x[i]][Y + y[i]] = true;
				q.push({ X + x[i], Y + y[i] });
				dist[X + x[i]][Y + y[i]] = cost + 1;
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
		char first, second;
		int fir, sec;
		scanf(" %c%d ", &first, &fir);
		scanf(" %c%d", &second, &sec);
		bfs({ first - 'a' + 1, fir }, { second - 'a' + 1, sec });
	}

	return 0;
}