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
	long long l1, r1, l2, r2, k, x, y;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	x = max(l1, l2);
	y = min(r1, r2);
	if (x > y)cout << 0<< endl;
	else
	{
		if (k >= x && k <= y) cout << y - x << endl;
		else cout << y - x + 1 << endl;
	}
	system("pause");
	return 0;
}