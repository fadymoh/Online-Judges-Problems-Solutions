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
	int n, temp;
	bool change = false, non_increasing = false;
	cin >> n;
	vector <int> myvector(n + 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> myvector[i] >> temp;
		if (myvector[i] != temp) change = true;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		temp = myvector[i];
		for (int j = i + 1; j < n; ++j)
		if (myvector[j] > temp) {
			non_increasing = true;
			break;
		}
		if (non_increasing) break;
	}
	if (change) cout << "rated" << endl;
	else if (!non_increasing) cout << "maybe" << endl;
	else cout << "unrated" << endl;
	system("pause");
	return 0;
}