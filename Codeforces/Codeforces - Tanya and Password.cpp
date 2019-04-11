#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

const int N = 128 + 3, M = 1e3 + 3;
//vector<vector<pair<int, int>>> adj;// first child, second edge ID
unordered_map<string, vector<pair<string, int>>> adj;
unordered_map<string, int> deg;
vector<string> res;
void euler(string u) {
	while (adj[u].size()) {
		auto cur = adj[u].back();
		adj[u].pop_back();
		euler(cur.first);
		//res.push_back(cur.second);
	}
	res.push_back(u);
}
string s[M];
char buffer[N];
int main()
{
	int m;
	scanf("%d", &m);
	char* a, b, c;
	for (int i = 0; i < m; ++i)
	{
		scanf("%s",buffer);
		s[i]= buffer;
		deg[s[i].substr(0, 2)]++;
		deg[s[i].substr(1, 2)]--;
	}
	for (int i = m - 1; i >= 0; --i)
		adj[s[i].substr(0, 2)].push_back({ s[i].substr(1, 2), i });
	string st = s[0].substr(0,2);
	bool ok = true, one = false;
	for (auto &vertex: deg) 
	{
		switch (vertex.second)
		{
			case 0:
			case -1:
				break;
			case 1:
				st = vertex.first;
				if (one++)
					ok = false;
				break;
			default:
				ok = false;
		}
	}
	euler(st);
	ok &= res.size() == m+1;
	if (!ok)
		puts("NO");
	else
	{
		puts("YES");
		int sz = res.size() - 1;
		printf("%c%c", res[sz][0], res[sz][1]);
		for (int i = sz - 1; i >= 0; --i)
			printf("%c", res[i][1]);
	}
	return 0;
}