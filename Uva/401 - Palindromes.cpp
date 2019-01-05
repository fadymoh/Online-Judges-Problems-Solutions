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
	string x, mirror;
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string s2 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

	map<char, char> M;

	for (int i = 0; i<s1.size(); i++) M[s1[i]] = s2[i];
	while (cin >> x){
		//cin >> x;
		int x_length = x.length();
		mirror = x;
		bool palindrome = true, mirror_flag = true;
		for (int i = 0; i <= x_length / 2; ++i)
		{
			if (x[i] != x[x_length - i - 1]) palindrome = false;
			if (x[x_length - i -1] != M[x[i]]) mirror_flag = false;
		}
		if (palindrome && mirror_flag) cout << x << " -- is a mirrored palindrome." << endl;
		else if (palindrome && !mirror_flag) cout << x << " -- is a regular palindrome." << endl;
		else if (!palindrome && mirror_flag) cout << x << " -- is a mirrored string." << endl;
		else cout << x << " -- is not a palindrome." << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}