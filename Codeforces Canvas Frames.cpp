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
struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n;
	unordered_map<int, int> mymap;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		mymap[x]++;
	}
	auto iter = mymap.begin();
	int counter = 0;
	while (iter != mymap.end())
	{
		counter += iter->second / 2;
		iter++;
	}
	cout << counter / 2 << endl;
	system("pause");
	return 0;
}