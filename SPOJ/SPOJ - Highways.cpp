#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> adjList;
const int N = 100005;
#define infinity 1e9
int dist[N];
/*
* Djikstra is a single source all destinations shortest path algorithm
* It doesnt handle negative cycles
* There are two versions, one for sparse graphs and one for dense one
* Check if your graph contains negative cycles, then we need to use bellman's ford
*/
void djikstra_NLogN(int source)
{
	memset(dist, 0x3f, sizeof dist);
	//distance of the source to itself is zero
	dist[source] = 0;
	priority_queue<pair<int, int>> myPQ;
	myPQ.push({ source, 0 });
	while (myPQ.size())
	{
		pair<int, int> top = myPQ.top();
		myPQ.pop();
		int u = top.first;
		int cost_to_u = -top.second;
		if (cost_to_u != dist[u]) continue;
		for (auto p : adjList[u])
		{
			int v = p.first;
			int cost = cost_to_u + p.second;
			if (dist[v] > cost)
			{
				dist[v] = cost;
				myPQ.push({ v,-cost });
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
		int n, m, source, dest;
		scanf("%d %d %d %d", &n, &m, &source, &dest); --source; --dest;
		int u, v, cost;
		adjList.resize(N);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &cost); --u; --v;
			adjList[u].push_back({ v ,cost });
			adjList[v].push_back({ u ,cost });
		}
		djikstra_NLogN(source);
		if (dist[dest] <  1e9) printf("%d\n", dist[dest]);
		else puts("NONE");
	}
	
}