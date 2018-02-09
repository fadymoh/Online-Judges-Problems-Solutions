/*#include <iostream>
#include <list>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector <int> > vii;
typedef vector<int> vi;
int main()
{
	int n, m, d, k, x;
	while (cin >> n >> m){
		//graph.assign(100000, vector <int>());
		//int arr[1000005];
		vector<int> graph[1000005];
		unordered_map<int, vector<int>> mymap;
		for (int i = 1; i <= n; i++){
			cin >> x;
			graph[x].push_back(i);
		}
		for (int i = 0; i < m; i++){
			cin >> k >> d;
			if (k - 1 < graph[d].size())
				cout << graph[d][k - 1] << endl;
			else
				cout << 0 << endl;
		}
	}
	system("pause");
	return 0;
}*/
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
	int n, m, d, k, x;
	while (scanf_s("%d %d", &n, &m) != EOF){
		unordered_map<int, vector<int>> mymap;
		for (int i = 1; i <= n; ++i)
		{
			scanf_s("%d", &x);
			mymap[x].push_back(i);
		}
		for (int i = 0; i < m; ++i)
		{
			scanf_s("%d %d", &k, &x);
			if (k > mymap[x].size()) printf("0\n");
			else printf("%d\n", mymap[x][k - 1]);
		}
	}

	return 0;
}