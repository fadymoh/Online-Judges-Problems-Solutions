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
bool is_beautiful(long long val)
{
	while (val > 0)
	{
		int x = val % 10;
		val /= 10;
		if (x != 1 && x != 2 && x != 3) return false;
	}
	return true;
}

void func(long long m, long long val)
{
	if (val == m) return;

	if (is_beautiful(val)) {
		cout << val << endl;
	}
	func(m, val + 1);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	while (cin >> x)
	{
		long long power = pow(10, x);
		func(power, pow(10, x - 1));
	}

	system("pause");
	return 0;
}