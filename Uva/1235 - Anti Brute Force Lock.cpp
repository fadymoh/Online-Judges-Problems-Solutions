#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
const int N = 505, M = 130000;

vector<int>p, v;
vector<pair<int, pair<int, int>>> edges;
void init()
{
	iota(p.begin(), p.end(), 0);
	sort(edges.begin(), edges.end());
}
int find(int a)
{
	return a == p[a] ? a : (p[a] = find(p[a]));
}
void join(int a, int b)
{
	p[find(a)] = find(b);
}
int n, m;
int kruskal() {

	int ret = 0;
	m = edges.size();
	for (int i = 0; i < m; ++i) {
		if (find(edges[i].second.first) == find(edges[i].second.second))
			continue;
		join(edges[i].second.first, edges[i].second.second);
		ret += edges[i].first;
	}
	return ret;
}
int getDiff(string to, string from)
{
	int res = 0;
	for (int i = 0; i < 4; ++i)
	{
		int diff = abs(to[i] - from[i]);
		res += min(10 - diff, diff);
	}
	return res;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		init();
		string in[N];
		p.resize(n); v.resize(n);
		edges.clear();
		int ret = 1e9;
		for (int i = 0; i < n; ++i)
		{
			cin >> in[i];
			ret = min(ret, getDiff("0000", in[i]));
		}
		m = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j) {
					edges.push_back({ getDiff(in[i], in[j]), {i,j}});
				}
			}
		}
		cout << ret + kruskal() << endl;
	}

	return 0;
}