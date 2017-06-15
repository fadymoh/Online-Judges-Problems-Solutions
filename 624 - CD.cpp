#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
int TC, x, ans, n;
vector <int> songs;
vector <bool> t, cp;

void backtrack(int label)
{
	if (label == n){
		int tmp = 0;
		for (int i = 0; i < n; i++) if (t[i]) tmp += songs[i];
		if (tmp <= TC){
			if (ans < tmp){
				ans = tmp;
				for (int i = 0; i < n; i++)  cp[i] = t[i];
			}
		}
		return;
	}
	t[label] = true;
	backtrack(label + 1);
	t[label] = false;
	backtrack(label + 1);
}
int main()
{
	while (cin >> TC){
		cin >> n;
		songs.clear();
		t.clear();
		cp.clear();
		t.resize(n);
		cp.resize(n);
		for (int i = 0; i < n; i++){
			cin >> x;
			songs.push_back(x);
		}
		ans = 0;
		backtrack(0);
		for (int i = 0; i < n; i++) if (cp[i]) cout << songs[i] << " ";
		cout << "sum: " << ans << endl;
	}
	system("pause");
	return 0;
}