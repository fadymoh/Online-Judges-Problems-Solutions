#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
vector <vector <char> >  x, y, common;
int k;
string l;
bool backtrack(int idx)
{
	if (idx == 5) {
		k--;
		return (k == 0);
	}
	for (auto c : common[idx]){
		l[idx] = c;
		if (backtrack(idx + 1)) return true;
	}
	return false;
}
int main()
{
	int TC;
	string str;
	cin >> TC;
	while (TC--){
		cin >> k;
		x.clear(); y.clear(); x.resize(5); y.resize(5);
		for (int i = 0; i < 6; i++){
			cin >> str;
			for (int j = 0; j < 5; j++) x[j].push_back(str[j]);
		}
		for (int i = 0; i < 6; i++){
			cin >> str;
			for (int j = 0; j < 5; j++) y[j].push_back(str[j]);
		}
		for (int i = 0; i < 5; i++) {
			sort(x[i].begin(), x[i].end());
			sort(y[i].begin(), y[i].end());
		}
		common.clear();
		common.resize(5);
		for (int i = 0; i < 5; i++) {
			for (auto c : x[i]) {
				if (binary_search(y[i].begin(), y[i].end(), c) &&
					!binary_search(common[i].begin(), common[i].end(), c)) {
					common[i].push_back(c);
				}
			}
		}
		 l = "*****";
		if (backtrack(0)) cout << l << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}


