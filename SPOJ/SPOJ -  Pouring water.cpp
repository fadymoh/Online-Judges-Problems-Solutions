#include <iostream>
#include <map>
#include <queue>
using namespace std;
int a, b, c;
int bfs()
{
	map<pair<int, int>, int> level;
	level[{0, 0}] = 0;
	queue<pair<int, int>> mQ;
	mQ.push({ 0,0 });
	while (!mQ.empty())
	{
		pair <int, int> mFront = mQ.front();
		mQ.pop();

	}
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> a >> b >> c;

	}

	return 0;
}