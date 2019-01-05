#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
int main()
{
	int TC;
	cin >> TC;
	cin.ignore();
	cin.ignore();
	string separator = "";
	while (TC--){
		string temp;
		vector <string> input, changed;
		while (getline(cin, temp) && temp != "")
			input.push_back(temp);
		sort(input.begin(), input.end());
		int i, j;
		changed.resize(input.size());
		changed = input;

		rep(i, 0, changed.size() - 1) changed[i].erase(remove(changed[i].begin(), changed[i].end(), ' '), changed[i].end());

		rep(i, 0, changed.size() - 1) sort(changed[i].begin(), changed[i].end());

		rep(i, 0, input.size() - 1){
			rep(j, i + 1, input.size() - 1){
				if (changed[i] == changed[j]) cout << input[i] << " = " << input[j] << endl;
			}
		}
		if (TC) cout << endl;
	}
	system("pause");
	return 0;
}


