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
	int t;
	cin >> t;
	int case_counter = 1;
	while (t--)
	{
		vector <pair <string, int>> myvector(52);
		bool seen[52];
		for (int i = 0; i < 52; i++)
			seen[i] = false;
		string temp;
		for (int i = 0; i < 52; i++)
		{
			cin >> temp;
			pair <string, int> mytemp;
			int x = (temp[0] >= 65 && temp[0] <= 90) ? 10:temp[0] - '0';
			mytemp = make_pair(temp, x);
			myvector[i] = mytemp;
		}
		int y = 0;
		int top_of_the_pile = 51 - 25;
		int counter = 0;
		for (int i = 0; i < 3; i++)
		{
			int x = myvector[top_of_the_pile].second;
			y += x;
			counter += (10-x)+1;
			top_of_the_pile -= (10-x+1);
		}
		cout <<"Case " << case_counter++ << ": "  <<myvector[counter+y-1].first << endl;

	}

	system("pause");
	return 0;
}