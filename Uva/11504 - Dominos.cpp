#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 1e6 + 3;
int dfsT[N], lo[N], curT;
vector<vector<int>> adj;
stack<int> stk;
int cmpID[N], nc;

void tarjanDFS(int u) {
	dfsT[u] = lo[u] = curT++;
	stk.push(u);
	for (auto v : adj[u]) {
		if (dfsT[v] == -1) {
			tarjanDFS(v);
			lo[u] = min(lo[u], lo[v]);
		}
		else if (cmpID[v] == -1) {
			lo[u] = min(lo[u], lo[v]);
		}
	}
	if (lo[u] == dfsT[u]) { // u root component
		int x;
		do {
			x = stk.top();
			stk.pop();
			cmpID[x] = nc;
		} while (x != u);
		++nc;
	}
}

void tarjan() {
	memset(dfsT, -1, adj.size() * sizeof dfsT[0]);
	memset(cmpID, -1, adj.size() * sizeof cmpID[0]);
	for (int i = 0; i < adj.size(); ++i) {
		if (dfsT[i] == -1)
			tarjanDFS(i);
	}
}
bool isSrc[N], isSnk[N];
void findSrcSnk() {
	memset(isSrc, 1, nc * sizeof isSrc[0]);
	memset(isSnk, 1, nc * sizeof isSnk[0]);
	// adj2 = vector<vector<int>>(nc); 
	for (int u = 0; u < adj.size(); ++u) {
		for (auto v : adj[u]) {
			if (cmpID[u] == cmpID[v])
				continue;
			//		adj2[compID[u]].push_back(compID[v]); // build new kernel DAG
			isSrc[cmpID[v]] = false;
			isSnk[cmpID[u]] = false;
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, m, u, v;
		scanf("%d %d", &n, &m);
		nc = 0;
		adj = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v); --u, --v;
			adj[u].push_back(v);
		}
		tarjan();
		findSrcSnk();
		int cnt = count(isSrc, isSrc + nc, 1);
		
		printf("%d\n", cnt);
	}

	return 0;
}