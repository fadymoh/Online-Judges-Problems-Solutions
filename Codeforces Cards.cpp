#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;
//rep(i, 0, changed.size() - 1) changed[i].erase(remove(changed[i].begin(), changed[i].end(), ' '), changed[i].end());
bool comparator (int i, int j) {
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
//priority_queue<int, std::vector<int>, greater_than<comparator>()> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, sum = 0, x;
	cin >> n;
	vector <pair <int, bool>> myvector(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		myvector[i] = make_pair(x, false);
		sum += x;
	}
	sum = sum / (n / 2);
	for (int i = 0; i < n - 1; ++i)
	{
		if (!myvector[i].second)
		for (int j = i + 1; j < n; ++j)
		{
			if (!myvector[j].second) if (myvector[i].first + myvector[j].first == sum) { myvector[j].second = true; myvector[i].second = true; cout << i + 1 << " " << j + 1 << endl; break; }
		}
	}
	system("pause");
	return 0;
}