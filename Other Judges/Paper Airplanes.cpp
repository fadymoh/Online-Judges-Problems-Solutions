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
//myvector2.erase(remove_if(myvector2.begin(), myvector2.end(), EmptyStr()), myvector2.end());
/*
struct EmptyStr
{
bool operator()(const std::string& s)
{
return (s == "");
}
};
*/
bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
//priority_queue<int, std::vector<int>, comparatorr> minHeap;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	float k, n, s, p, total = 0, sheets_per_person;
	cin >> k >> n >> s >> p;
		sheets_per_person = ceil(n / s);
		cout << int(ceil((sheets_per_person * k) / p)) << endl;
	system("pause");
	return 0;
}