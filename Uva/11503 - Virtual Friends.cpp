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
class UF    {
	int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
	UF(int N)   {
		cnt = N;
		id = new int[N];
		sz = new int[N];
		for (int i = 0; i<N; i++)	{
			id[i] = i;
			sz[i] = 1;
		}
	}
	~UF()	{
		delete[] id;
		delete[] sz;
	}
	int find(int p)	{
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root) {
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}
	int merge(int x, int y)	{
		int i = find(x);
		int j = find(y);
		if (i != j)
		{
			if (sz[i] < sz[j])	{
				id[i] = j;
				sz[j] += sz[i];
				cnt--;
				return sz[j];
			}
			else	{
				id[j] = i;
				sz[i] += sz[j];
				cnt--;
				return sz[i];
			}
		}
		return sz[i];
	}
	bool connected(int x, int y)    {
		return find(x) == find(y);
	}
	int count() {
		return cnt;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, connections;
	cin >> t;
	while (t--)
	{
		cin >> connections;
		string str1, str2;
		unordered_map <string, int> mymap;
		UF myunion(2*connections + 1);
		int count = 0;
		for (int i = 0; i < connections; ++i)
		{
			cin >> str1 >> str2;
			if (mymap[str1] == 0) mymap[str1] = ++count;
			if (mymap[str2] == 0) mymap[str2] = ++count;
			cout << myunion.merge(mymap[str1], mymap[str2]) << endl;
		}
	}
	system("pause");
	return 0;
}