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
bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
//priority_queue<int, std::vector<int>, comparatorr> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <long long> myvector(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> myvector[i];
	int counter = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long long x = myvector[i] + myvector[j];
			if (!(x & (x - 1)))
			{
				counter++;
			}
		}
	}
	cout << counter << endl;
	system("pause");
	return 0;
}