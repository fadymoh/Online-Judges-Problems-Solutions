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
	int round_number;
	while (cin >> round_number, round_number != -1)
	{
		cout << "Round " << round_number << endl;
		unordered_map <char, bool> mymap;
		int wrong_strikes = 0, correct_strikes = 0;
		string name, comparison;
		cin >> name >> comparison;
		for (int i = 0; i < comparison.length(); ++i)
		{
			bool flag = false;
			if (!mymap[comparison[i]]){
				for (int j = 0; j < name.length(); ++j)
				{
					if (comparison[i] == name[j])
					{
						correct_strikes++;
						flag = true;
					}
				}
				if (!flag) wrong_strikes++;
			}

				if (correct_strikes == name.length()) {
					cout << "You win." << endl;
					break;
				}
				else if (wrong_strikes == 7){
					cout << "You lose." << endl;
					break;
				}
			mymap[comparison[i]] = true;
		}
		if (correct_strikes < name.length() && wrong_strikes < 7) cout << "You chickened out." << endl;
	}

	system("pause");
	return 0;
}