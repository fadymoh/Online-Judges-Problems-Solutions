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
//rep(i, 0, x.size() - 1) x[i].erase(remove(x[i].begin(), x[i].end(), ' '), x[i].end());
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
	string x;
	int t;
	cin >> t;
	cin.ignore();
	for (int k = 1; k <= t; ++k)
	{
		getline(cin,x);

		x.erase(remove(x.begin(), x.end(), ' '), x.end());
		x.erase(remove(x.begin(), x.end(), ','), x.end());
		x.erase(remove(x.begin(), x.end(), '!'), x.end());
		x.erase(remove(x.begin(), x.end(), '?'), x.end());
		x.erase(remove(x.begin(), x.end(), '('), x.end());
		x.erase(remove(x.begin(), x.end(), ')'), x.end());
		x.erase(remove(x.begin(), x.end(), '.'), x.end());

		cout << "Case #" << k << ":\n";
		float y = sqrt(x.length());

		if (y - int(sqrt(x.length())) > 0) cout << "No magic :(" << endl;
		else {
			bool magical = true;
			for (int i = 0; i <= y / 2; ++i)
			{
				for (int j = i * y; j < i * y + y; ++j)
				{
					if (x[j] != x[y * y - 1 - j]) magical = false;
				}
			}
			if (magical) cout << y << endl;
			else cout << "No magic :(" << endl;
		}
	}
	system("pause");
	return 0;
}