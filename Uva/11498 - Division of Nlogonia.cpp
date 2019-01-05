#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <cmath>
#include <iomanip>
using namespace std;
//rep(i, 0, changed.size() - 1) changed[i].erase(remove(changed[i].begin(), changed[i].end(), ' '), changed[i].end());
struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};
priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	while (cin >> t, t != 0)
	{
		int x, y;
		cin >> x >> y;
		while (t--)
		{
			int temp_x, temp_y;
			cin >> temp_x >> temp_y;
			if (temp_x == x || temp_y == y) cout << "divisa" << endl;
			else if (temp_x > x && temp_y > y) cout << "NE" << endl;
			else if (temp_x > x && temp_y < y) cout << "SE" << endl;
			else if (temp_x < x && temp_y > y) cout << "NO" << endl;
			else cout << "SO" << endl;
		}
	}

	system("pause");
	return 0;
}