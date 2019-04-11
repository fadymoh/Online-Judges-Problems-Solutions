#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 128 + 3, M = 1024 + 3;
vector<vector<pair<int, int>>> adj;// first child, second edge ID
bool vis[M];
int deg[N];
vector<int> res;
int tc, n;
char buffer[N];
string s[M];

void euler(int u) {
	while (adj[u].size()) {
		auto cur = adj[u].back();
		adj[u].pop_back();
		euler(cur.first);
		res.push_back(cur.second);
	}
}
int main()
{
	scanf("%d", &tc);
	while (tc--)
	{
		adj = vector<vector<pair<int, int>>>(N);
		res.clear();
		memset(deg, 0, sizeof deg);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", buffer);
			s[i] = buffer;
			deg[s[i].front()]++;
			deg[s[i].back()]--;
		}
		sort(s, s + n);
		for (int i = n - 1; i >= 0; --i)
			adj[s[i].front()].push_back({ s[i].back(), i });
		int st = s[0][0];
		bool ok = true, one = false;
		for (int i = 'a'; i <= 'z'; ++i) {
			switch (deg[i]) {
			case 0:
			case -1:
				break;
			case 1:
				st = i;
				if (one++)
					ok = false;
				break;
			default:
				ok = false;
			}
		}
		euler(st);
		ok &= res.size() == n;
		if (!ok)
			puts("The door cannot be opened.");
		else
			puts("Ordering is possible.");
	}

	return 0;
}