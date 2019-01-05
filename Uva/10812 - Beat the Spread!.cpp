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
//rep(i, 0, changed.size() - 1) changed[i].erase(remove(changed[i].begin(), changed[i].end(), ' '), changed[i].end());

#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
int main()
{
	int TC;
	cin >> TC;
	while (TC--){
		int s, d, x, y;
		cin >> s >> d;
		y = abs(s - d) / 2;
		x = s - y;
		if (x + y == s && abs(x - y) == d)
			cout << max(x, y) << " " << min(x, y) << endl;
		else cout << "impossible" << endl;
	}


	system("pause");
	return 0;
}
