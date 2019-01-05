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
#include <set>
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
class UnionFind { // OOP style
private: vector<int> p, rank; // remember: vi is vector<int>
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, computers, x, y;
	cin >> t;
	string s;
	while (t--)
	{
		cin >> computers;
		UnionFind myunion(computers+1);
		int successfull = 0 , unsuccessfull = 0;
		char c;

		while (1){
			if (!getline(cin, s) || s.empty()) break; //end of pairs
			sscanf_s(s.c_str(), "%c %d %d", &c, &x, &y);
			if (c == 'c') myunion.unionSet(x, y);
			else (myunion.isSameSet(x, y)) ? successfull++:unsuccessfull++;

		}
		cout << successfull << ',' << unsuccessfull << endl;
		if (t != 0) cout << endl;
	}
	system("pause");
	return 0;
}