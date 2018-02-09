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
priority_queue<int, std::vector<int>, comparator> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, counter_c = 1;
	cin >> n >> m;
	while (n)
	{
		char x[102][102];
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> x[i][j];
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (x[i][j] != '*')
			{
				int counter = 0;
				for (int k = 0; k < 3; ++k)
				{
					for (int l = 0; l < 3; ++l)
					{
						int x_coordinate = i + k - 1;
						int y_coordinate = j + l - 1;
						if (x_coordinate >= 0 && y_coordinate >= 0 && x_coordinate < n && y_coordinate < m && x[x_coordinate][y_coordinate] == '*')
							counter++;
					}
				}
				x[i][j] = counter + '0';
			}
		}
		cout << "Field #" << counter_c++ << ":\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << x[i][j];
			cout << endl;
		}
		cin >> n >> m;
		if (n) cout << endl;
	}

	system("pause");
	return 0;
}