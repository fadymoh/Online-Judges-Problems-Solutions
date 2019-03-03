#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;
const int N = 128;
int mat[N][N];
int X[N], Y[N];
bool visited[N];
int n;
void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < n; ++i)
		if (mat[node][i] && !visited[i])
			dfs(i);
}

int main()
{

	int  u, v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &X[i], &Y[i]);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (X[i] == X[j] || Y[i] == Y[j]) mat[i][j] = 1;
		}
	}
	int answer = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i]) // We basically count the number of connected components
		{
			dfs(i);
			++answer;
		}
	}
	printf("%d", answer);
	return 0;
}