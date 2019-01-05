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
	int n, k, x;
	cin >> n >> k;
	vector <int> arr1(n), arr2(k);
	for (int i = 0; i < n; ++i)
		cin >> arr1[i];
	for (int i = 0; i < k; ++i)
		cin >> arr2[i];
	sort(arr2.begin(), arr2.end(), comparatorr);
	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr1[i] == 0) arr1[i] = arr2[counter++];
		if (counter == k) break;
	}
	bool flag = false;
	for (int i = 0; i < n-1; ++i)
	{
		if (arr1[i] > arr1[i + 1]) { flag = true; break; }
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	system("pause");
	return 0;
}