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
//myvector2.erase(remove_if(myvector2.begin(), myvector2.end(), EmptyStr()), myvector2.end());
/*
struct EmptyStr
{
bool operator()(const std::string& s)
{
return (s == "");
}
};
*/
struct comparatorr {
	bool operator() (const int &one, const int &two)
	{
		return one > two;
	}
};
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
priority_queue<int, std::vector<int>, comparatorr> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n != 0)
	{
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			minHeap.push(temp);
		}
		int counter = 0;
		while (minHeap.size() > 1)
		{
			int first = minHeap.top(); minHeap.pop();
			int second = minHeap.top(); minHeap.pop();
			counter += (second + first);
			minHeap.push(second + first);
		}
		minHeap.pop();
		cout << counter << endl;
	}

	system("pause");
	return 0;
}