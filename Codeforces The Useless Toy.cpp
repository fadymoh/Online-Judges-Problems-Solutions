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
	char start, end;
	int arr[5] = {118,60,94,62, 118};
	unordered_map <int, int> mymap;
	cin >> start >> end;
	long long n;
	cin >> n;
	n %= 4;
	if (n == 0 || n == 2) cout << "undefined" << endl;
	else
	{

		switch (start)
		{
		case 118:
			if (n == 1)
				if (arr[1] == end) cout << "cw";
				else cout << "ccw";
			else
				if (arr[3] == end) cout << "cw";
				else cout << "ccw";
			break;
		case 60:
			if (n == 1)
				if (arr[2] == end) cout << "cw";
				else cout << "ccw";
			else
				if (arr[0] == end) cout << "cw";
				else cout << "ccw";
			break;
		case 94:
			if (n == 1)
				if (arr[3] == end) cout << "cw";
				else cout << "ccw";
			else
				if (arr[1] == end) cout << "cw";
				else cout << "ccw";
			break;
		default:
			if (n == 1)
				if (arr[4] == end) cout << "cw";
				else cout << "ccw";
			else
				if (arr[2] == end) cout << "cw";
				else cout << "ccw";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}