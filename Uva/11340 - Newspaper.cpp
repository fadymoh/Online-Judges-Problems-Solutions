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
	int t, k, m;
	double temp;
	cin >> t;
	while (t--)
	{
		unordered_map<char, double> mymap;
		cin >> k;
		char a;
		for (int i = 0; i < k; ++i)
		{
			cin >> a >> temp;
			mymap[a] = temp;
		}
		cin >> m;
		double sum = 0;
		cin.ignore();
		for (int i = 0; i < m; ++i)
		{
			string x;
			getline(cin, x);
			for (int j = 0; j < x.length(); ++j)
			{
				auto t = mymap.find(x[j]);
				if (t != mymap.end())
					sum += mymap[x[j]];
			}
		}
		cout << fixed << setprecision(2) << sum / 100 << '$' << endl;
	}
	system("pause");
	return 0;
}