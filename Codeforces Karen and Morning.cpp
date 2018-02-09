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
bool is_palindrone(string x)
{
	string y = x;
	reverse(y.begin(), y.end());
	return (x == y) ? 1 : 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string x;
	cin >> x;
	int counter = 0;
	while (!is_palindrone(x))
	{
		if (x[4] == '9')
		{
			if (x[3] == '5')
			{
				if (x[1] == '3' && x[0] == '2')
				{
					x = "00:00";
				}
				else if (x[1] == '9')
				{
					x[0]++;
					x[1] = x[3] = x[4] = '0';
				}
				else
				{
					x[1]++;
					x[3] = x[4] = '0';
				}
			}
			else
			{
				x[4] = '0';
				x[3]++;
			}
		}
		else x[4]++;
		counter++;
	}
	cout << counter << endl;
	system("pause");
	return 0;
}