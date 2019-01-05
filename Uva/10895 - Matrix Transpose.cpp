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
	int m, n, r;
	while (scanf_s("%d %d", &m, &n) != EOF)
	{
		vector <vector <pair<int, int> > > mymatrix(m+1);
		vector <vector <pair<int, int> > > myTranspose(n+1);

		for (int k = 1; k <= m; ++k){
			cin >> r;
			vector <int> positions(r);
			vector <int> values(r);
			for (int i = 0; i < r; ++i)
				cin >> positions[i];
			for (int i = 0; i < r; ++i)
				cin >> values[i];
			for (int i = 0; i < r; ++i)
				mymatrix[k].push_back(make_pair(positions[i], values[i]));
		}

		for (int i = 1; i <= m; ++i)
			for (int j = 0; j < mymatrix[i].size(); ++j)
				myTranspose[mymatrix[i][j].first].push_back(make_pair(i,mymatrix[i][j].second));
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; ++i)
		{
			cout << myTranspose[i].size();
			for (int j = 0; j < myTranspose[i].size(); ++j)
			{
				cout << ' ' << myTranspose[i][j].first;
			}
			cout << endl;
			for (int j = 0; j < myTranspose[i].size(); ++j)
			{
				cout << myTranspose[i][j].second;
				if (j < myTranspose[i].size() - 1) cout << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}