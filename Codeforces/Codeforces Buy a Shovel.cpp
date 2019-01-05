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
	int k, r;
	cin >> k >> r;
	int counter = 1;
	while ((counter*k) % 10 != r && (counter*k) % 10 != 0)
	{
		counter++;
	}
	cout << counter << endl;
	system("pause");
	return 0;
}