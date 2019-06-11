#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<char, vector<int>> grid;
bool visited[128];
string s;
bool validNode(char checkUpon)
{
	for (auto node : grid[checkUpon])
		if (visited[node]) return false;
	return true;
}
bool dfs(string path)
{
	if (path.length() == s.size())
	{
		int sz = path.size();
		for (int i = 0; i < sz; ++i)
			printf("%c%c", path[i], " \n"[i == (sz - 1)]);
		return true;
	}
	bool ret = false;

	for (int i = 0; i < s.size(); ++i)
	{
		char key = s[i];
		if (!visited[key])
			if (validNode(key))
			{
				visited[key] = true;
				ret = dfs(path + key) || ret;
				visited[key] = false;
			}
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	string line;
	while (tc--)
	{
		getchar();
		getline(cin, line);
		stringstream ss;
		ss << line;
		s.clear();
		int n;
		while (ss >> line) s += line;
		sort(s.begin(), s.end());
		getline(cin, line);
		ss.clear();
		ss << line;
		grid.clear();
		while (ss >> line)
			grid[line[0]].push_back(line[2]);
		if (!dfs("")) puts("NO");
		if (tc) puts("");
	}
	return 0;
}