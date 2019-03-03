#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int n;
vector<vector<int>> adjacencyList;
int dst[100005];
void bfs()
{
	memset(dst, -1, sizeof dst);
	queue<int> myQ;
	myQ.push(n - 1);
	dst[n - 1] = 0;
	while (!myQ.empty())
	{
		int cur = myQ.front();
		myQ.pop();

		for (int ng : adjacencyList[cur])
		{
			if (dst[ng] == -1)
			{
				dst[ng] = dst[cur] + 1;
				myQ.push(ng);
			}
		}
	}
}
int main()
{
	int tc, d;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		adjacencyList.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> d;
			if (i + d < n)
				adjacencyList[i + d].push_back(i);
			if (i - d >= 0)
				adjacencyList[i - d].push_back(i);
		}
		bfs();
		for (int i = 0; i < n; ++i)
			cout << dst[i] << '\n';
	}

	return 0;
}