#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char, vector<int>> a;
unordered_map<char, vector<int>> b;
const int N = 150005;
char buffer[N];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", buffer);
	for (int i = 0; i < n; ++i)
			a[buffer[i]].push_back(i+1);
	scanf("%s", buffer);
	for (int i = 0; i < n; ++i)
			b[buffer[i]].push_back(i+1);
	vector<pair<int, int>> solution;
	unordered_map<char,int> indexRight(27), indexLeft(27);
	for (auto &el : a)
		if (b.find(el.first) != b.end() && el.first != '?')
		{
			int sz = min(el.second.size(), b[el.first].size());
			indexRight[el.first] = indexLeft[el.first] = sz;
			for (int i = 0; i < sz; ++i)
				solution.push_back({ el.second[i],b[el.first][i] });
		}

	for (auto it = a.begin(); it != a.end(); it++)
	{
		auto el = *it;
		if (el.first != '?')
			for (int i = indexRight[el.first]; i < a[el.first].size() && b['?'].size(); ++i)
			{
				solution.push_back({ a[el.first][i], b['?'][0] });
				b['?'].erase(b['?'].begin());
			}
	}

	for (auto it = b.begin(); it != b.end(); it++)
	{
		auto el = *it;
		if (el.first != '?')
			for (int i = indexLeft[el.first]; i < b[el.first].size() && a['?'].size(); ++i)
			{
				solution.push_back({ a['?'][0],b[el.first][i] });
				a['?'].erase(a['?'].begin());
			}
	}

	int questionSize = min(b['?'].size(), a['?'].size());
	for (int i = 0; i < questionSize; ++i)
		solution.push_back({ a['?'][i],b['?'][i] });

	printf("%d\n", solution.size());
	int solSize = solution.size();
	for (int i = 0; i < solSize; ++i)
		printf("%d %d\n", solution[i].first, solution[i].second);
	return 0;
}