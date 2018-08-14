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
bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string x;
	cin >> x;
	int pearl = 0, link = 0;
	for (int i = 0; i < x.length(); ++i)
		if (x[i] == 'o') ++pearl;
		else ++link;
		if (pearl == 0) cout << "NO";
		else if (link % pearl == 0) cout << "YES";
		else cout << "NO";

	system("pause");
	return 0;
}