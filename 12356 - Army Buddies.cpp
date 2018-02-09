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
	int s, b;
	while (cin >> s >> b, s != 0 && b != 0)
	{
		int shmalak_feen[100001], yemenak_bardo_feen[100001];
		for (int i = 1; i <= s; ++i)
		{
			shmalak_feen[i] = i - 1;
			yemenak_bardo_feen[i] = i + 1;
		}
		yemenak_bardo_feen[s] = 0;
		int l, r;
		for (int i = 0; i < b; ++i)
		{
			cin >> l >> r;
			shmalak_feen[yemenak_bardo_feen[r]] = shmalak_feen[l];
			if (shmalak_feen[l] == 0)
				cout << "* ";
			else cout << shmalak_feen[l] << " ";
			yemenak_bardo_feen[shmalak_feen[l]] = yemenak_bardo_feen[r];
			if (yemenak_bardo_feen[r] == 0)
				cout << "*" << endl;
			else cout << yemenak_bardo_feen[r] << endl;
		}
		cout << '-' << endl;
	}

	system("pause");
	return 0;
}