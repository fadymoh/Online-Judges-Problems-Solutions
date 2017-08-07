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
	int TC, x,y;
	cin >> TC;
	while (TC--)
	{
		cin >> x >> y;
		if (x == y) cout << "=";
		else if (x < y) cout << "<";
		else cout << ">";
		if (TC)cout << endl;
	}
	system("pause");
	return 0;
}
