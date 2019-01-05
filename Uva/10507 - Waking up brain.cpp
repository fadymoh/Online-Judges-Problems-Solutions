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
bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
//priority_queue<int, std::vector<int>, comparatorr> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
class SegmentTree { // the segment tree is stored like a heap array
private: vector<int> st, A; // recall that vi is: typedef vector<int> vi;
		 int n;
		 int left(int p) { return p << 1; } // same as binary heap operations
		 int right(int p) { return (p << 1) + 1; }
		 void build(int p, int L, int R) { // O(n)
			 if (L == R) // as L == R, either one is fine
				 st[p] = L; // store the index
			 else { // recursively compute the values
				 build(left(p), L, (L + R) / 2);
				 build(right(p), (L + R) / 2 + 1, R);
				 int p1 = st[left(p)], p2 = st[right(p)];
				 st[p] = (A[p1] <= A[p2]) ? p1 : p2;
			 }
		 }
		 int rmq(int p, int L, int R, int i, int j) { // O(log n)
			 if (i > R || j < L) return -1; // current segment outside query range
			 if (L >= i && R <= j) return st[p]; // inside query range
			 // compute the min position in the left and right part of the interval
			 int p1 = rmq(left(p), L, (L + R) / 2, i, j);
			 int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
			 if (p1 == -1) return p2; // if we try to access segment outside query
			 if (p2 == -1) return p1; // same as above
			 return (A[p1] <= A[p2]) ? p1 : p2; // as in build routine
		 }
public:
	SegmentTree(const vector<int> &_A) {
		A = _A; n = (int)A.size(); // copy content for local usage
		st.assign(4 * n, 0); // create large enough vector of zeroes
		build(1, 0, n - 1); // recursive build
	}
		int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector <int> values(n);
	vector <int> frequency(n);
	unordered_map<int, int> mymap;
	int counter = 1;
	int x;
	cin >> x;
	values[0] = x;
	mymap[x]++;
	int initial = 0, end;
	bool flag = true;
	for (int i = 1; i < n; ++i)
	{
		cin >> values[i];
		mymap[values[i]]++;

		if (values[i] != values[i - 1])
		{
			int temp = mymap[values[i - 1]];
			for (int j = initial; j < i; ++j)
				frequency[j] = temp;
			initial = i;
			flag = false;
		}
	}
	if (initial != n)
	{
		int temp = mymap[values[n - 1]];
		for (int j = initial; j <n; ++j)
			frequency[j] = temp;
	}

	system("pause");
	return 0;
}