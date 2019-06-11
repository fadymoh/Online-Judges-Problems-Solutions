#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int N = 100 + 3;
const int M = 100 + 3;
vector<string> grid;
int visited[N][M];
int vid;
int x[9] = { -1,0, 1,0 ,-1,1,  1, -1 , 0};
int y[9] = { 0 ,1, 0,-1,1 ,1, -1, -1 , 0};
int n, m;
int ans;
void floodfill(pair<int, int> source)
{
	if (source.first < 0 || source.second < 0 || source.first >= grid.size() || source.second >= grid[0].size()) return;
	if (visited[source.first][source.second] == vid || grid[source.first][source.second] != 'W') return;
	visited[source.first][source.second] = vid;
	++ans;
	for (int i = 0; i < 9; ++i)
		floodfill({ source.first + x[i], source.second + y[i] });
}

int main()
{
	int tc;
	cin >> tc;
	string s;
	getline(cin, s);
	getline(cin, s);
	while (tc--)
	{
		n = 0;
		grid.clear();
		while (1)
		{
			getline(cin, s);
			if (s[0] != 'W' && s[0] != 'L') break;
			grid.push_back(s);
		}
		istringstream in(s);
		pair<int, int> source;
		++vid;
		in >> source.first >> source.second;
		--source.first, --source.second;
		ans = 0;
		floodfill(source);
		cout << ans << endl;
		while (getline(cin, s))
		{
			if (s.empty()) break;
			istringstream temp(s);
			++vid;
			temp >> source.first >> source.second;
			--source.first, --source.second;
			ans = 0;
			floodfill(source);
			cout << ans << endl;
		}
		if (tc) cout << '\n';
	}
	
	return 0;
}