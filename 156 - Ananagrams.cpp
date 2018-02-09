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
	vector <pair<string, bool> > myvector;
	vector <string> myvector_sorted;

	string x;
	while (cin >> x)
	{
		if (x == "#") break;
		string word = x;
		transform(x.begin(), x.end(), x.begin(), ::toupper);
		sort(x.begin(), x.end());
		pair <string, bool> temp = make_pair (word, false);
		myvector.push_back(temp);
		myvector_sorted.push_back(x);

	}
	for (int i = 0; i < myvector.size(); ++i)
	{
		bool anagram = true;
		for (int j = 0; j < myvector.size(); ++j)
		{
			if (i == j) continue;
			if (!myvector[i].second && myvector_sorted[i] == myvector_sorted[j]) {
				myvector[i].second = true;
				myvector[j].second = true;
			}

		}
	}
	sort(myvector.begin(), myvector.end(), sortbysec);
	for (int i = 0; i < myvector.size(); ++i)
	{
		if (!myvector[i].second) cout << myvector[i].first << endl;
	}
	

	system("pause");
	return 0;
}