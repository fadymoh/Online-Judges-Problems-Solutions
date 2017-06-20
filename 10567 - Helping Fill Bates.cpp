#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	map <char, vector<int> > states;
	string x;
	int Q;
	cin >> x;
	for (int i = 0; i < x.length(); i++)
		states[x[i]].push_back(i);
	cin >> Q;

	for (int i = 0; i < Q; i++){
		cin >> x;
		int index = -1, j = 0, begin = 0, val;
		bool flag = true;
		for (j = 0; j < x.length(); j++){
			vector<int>::iterator it = upper_bound(states[x[j]].begin(), states[x[j]].end(), index);
			index = it - states[x[j]].begin();
			if (it == states[x[j]].end()) {
				flag = false; break;
			}
			index = states[x[j]][index];
			if (j == 0)	begin = index;
		}
		if (flag) cout << "Matched " << begin << " " << index  << endl;
		else cout << "Not matched" << endl;
	}
	system("pause");
	return 0;
}
