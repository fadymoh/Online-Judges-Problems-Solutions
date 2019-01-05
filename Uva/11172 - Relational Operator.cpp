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
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y;
		char temp;
		cin >> x >> y;
		(x < y) ? temp = '<' : (x > y)? temp = '>': temp = '=';
		cout << temp << endl;
	}


	system("pause");
	return 0;
}

