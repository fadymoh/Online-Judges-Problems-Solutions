#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

const int N = 2000 + 3;
unordered_map<string, int> dfsT, lo, cmpID;
int curT, nc;
unordered_map<string, vector<string>> adj;
stack<string> stk;

void tarjanDFS(string u)
{
	dfsT[u] = curT= lo[u] = curT++;
	stk.push(u);
	for (auto v : adj[u])
	{
		if (dfsT[v] == -1)
		{
			tarjanDFS(v);
			lo[u] = min(lo[u], lo[v]);
		}
		else if (cmpID[v] == -1)
		{
			lo[u] = min(lo[u], lo[v]);
		}
	}
	if (lo[u] == dfsT[u]) // u root component
	{
		string x;
		do
		{
			x = stk.top();
			stk.pop();
			cmpID[x] = nc;
		} while (x != u);
		++nc;
	}
}
void tarjan()
{
	//memset(dfsT, -1, adj.size() * sizeof dfsT[0]);
	//memset(cmpID, -1, adj.size() * sizeof cmpID[0]);
	dfsT.clear();
	cmpID.clear();
	for (auto it: adj)
		if (dfsT[it.first] == -1)
			tarjanDFS(it.first);
}

unordered_map<string, bool> isSrc, isSnk;

void findSrcSnk()
{
	isSnk.clear();
	isSnk.clear();
	for (auto u: adj)
	{
		for (auto v : adj[u.first])
		{

		}
	}
}

int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		string u, v; ss >> u;
		
		while (ss >> v)
		{
			adj[u].push_back(v);
		}
		tarjan();

	}
	return 0;
}