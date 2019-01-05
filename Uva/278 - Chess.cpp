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
	int TC, n, m;
	cin >> TC;
	while (TC--){
		char kind;
		cin >> kind >> m >> n;
		int ans;
		if (kind == 'k') ans = ((m*n) % 2 == 0) ? (m*n) / 2 : ((m*n) / 2) + 1;
		else if (kind == 'Q' || kind == 'r') ans = min(m, n);
		else ans = (((m + 1) / 2) * ((n + 1) / 2));
		cout << ans << endl;
	}


	system("pause");
	return 0;
}


