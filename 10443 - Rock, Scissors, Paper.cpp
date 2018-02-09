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
	int test_cases;
	char arr[101][101], output[101][101];
	cin >> test_cases;
	while (test_cases--){
		int n, m, days;
		cin >> n >> m >> days;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> arr[i][j];
			output[i][j] = arr[i][j];
		}
		for (int k = 0; k < days; ++k){
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j){
					int up = i - 1, down = i + 1, left = j - 1, right = j + 1;
					if (up > -1)
						switch (arr[i][j])
						{
						case 'P':
							if (arr[up][j] == 'S') output[i][j] = 'S';
							break;
						case 'R':
							if (arr[up][j] == 'P') output[i][j] = 'P';
							break;
						case 'S':
							if (arr[up][j] == 'R') output[i][j] = 'R';
							break;
						}
					if (down < n)
						switch (arr[i][j])
						{
						case 'P':
							if (arr[down][j] == 'S') output[i][j] = 'S';
							break;
						case 'R':
							if (arr[down][j] == 'P') output[i][j] = 'P';
							break;
						case 'S':
							if (arr[down][j] == 'R') output[i][j] = 'R';
							break;
						}
					if (left > -1)
						switch (arr[i][j])
						{
						case 'P':
							if (arr[i][left] == 'S') output[i][j] = 'S';
							break;
						case 'R':
							if (arr[i][left] == 'P') output[i][j] = 'P';
							break;
						case 'S':
							if (arr[i][left] == 'R') output[i][j] = 'R';
							break;
						}
					if (right < m)
						switch (arr[i][j])
						{
						case 'P':
							if (arr[i][right] == 'S') output[i][j] = 'S';
							break;
						case 'R':
							if (arr[i][right] == 'P') output[i][j] = 'P';
							break;
						case 'S':
							if (arr[i][right] == 'R') output[i][j] = 'R';
							break;
						}
				}
			for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				arr[i][j] = output[i][j];
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j)
				cout << arr[i][j];
			cout << endl;
		}
		if (test_cases) cout << endl;
	}
	system("pause");
	return 0;
}