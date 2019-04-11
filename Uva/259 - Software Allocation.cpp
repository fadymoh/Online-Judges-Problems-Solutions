#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e4 + 3, M = 2e4 + 3;
int head[N], nxt[M], to[M], cap[M], ne, n, m, src, snk;

void init()
{
	memset(head, -1, n * sizeof head[0]);
	ne = 0;
}

void addEdge(int u, int v, int c)
{
	to[ne] = v;
	cap[ne] = c;
	nxt[ne] = head[u];
	head[u] = ne;
	++ne;
}

void addAugEdge(int u, int v, int c)
{
	addEdge(u, v, c);
	addEdge(v, u, 0);
}

int vis[N], visID;

int dfs(int u, int minCap)
{
	if (u == snk || minCap == 0) return minCap;
	if (vis[u] == visID) return 0;
	vis[u] = visID;
	for (int k = head[u]; k != -1; k = nxt[k]) {
		int v = to[k];
		int c = dfs(v, min(minCap, cap[k]));
		if (c) {
			cap[k] -= c;
			cap[k ^ 1] += c;
			return c;
		}
	}
	return 0;
}

int maxFlow()
{
	int flow = 0, ret = 0;
	do {
		++visID;
		flow = dfs(src, 1e9);
		ret += flow;
	} while (flow);
	return ret;
}
int main()
{
	while (!cin.eof()) {
		n = 130; src = 128, snk = 129;
		int finalRes = 0;
		string applications = "";
		string str;
		getline(cin, str);
		init();
		while (str != "") {
			int u = str[0];
			applications += char(u);
			int cap = str[1] - '0';
			finalRes += cap;
			int length = str.length();
			addAugEdge(src, u, cap);
			for (int i = 0; i < length - 4; ++i)
				addAugEdge(u, str[length - 2 - i], 1);
			if (cin.eof()) break;
			getline(cin, str);
		}
		for (int i = '0'; i <= '9'; ++i)
			addAugEdge(i, snk, 1);
		if (maxFlow() == finalRes) {
			string output = "__________";
			for (int i = 0; i < applications.length(); ++i)
				for (int k = head[applications[i]]; k != -1; k = nxt[k])
				{
					int c = cap[k];
					int v = to[k];
					if (!c)
						output[v - '0'] = applications[i];
				}
			cout << output << endl;
		}
		else puts("!");
	}
	return 0;
}