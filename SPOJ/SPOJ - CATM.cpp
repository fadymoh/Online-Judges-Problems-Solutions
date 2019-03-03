#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int dstcat[102][102];
int dstmouse[102][102];
int n, m;


void bfs(const vector <pair <int, int>> &src, int dst[102][102])
{
	memset(dst, 0x3f, sizeof dst);

	queue<pair <int, int>> q;
	
	for (auto p : src)
	{
		dst[p.first][p.second] = 0;
		q.push(p);
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int cdst = dst[cur.first][cur.second] + 1;

		int di = 0, dj = 1;
		for (int k = 0; k < 4; ++k)
		{
			int ni = cur.first + di;
			int nj = cur.second + dj;

			if (cdst < dst[ni][nj])
			{
				dst[ni][nj] = cdst;
				q.push({ ni, nj });
			}
			swap(di, dj);
			if (k == 1)
			{

			}
		}
	}

}

int main()
{

	return 0;
}