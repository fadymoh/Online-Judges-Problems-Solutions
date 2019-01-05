#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <cmath>
#include <iomanip>
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
	float height, day, night;
	double fatigue;
	while (cin >> height >> day >> night >> fatigue, height != 0)
	{
		fatigue = fatigue / 100;
		fatigue = day*fatigue;

		float current_height = 0;
		int counter = 0;
		bool flag = true;
		while (current_height <= height)
		{
			
			
			current_height += day;
			counter++;
			if (current_height > height) break;
			current_height -= night;
			if (day > 0)
			day -= fatigue;
			if (current_height < 0){
				flag = false;
				break;
			}
			//cout << " fe eh" << endl;
		}
		if (flag) cout << "success on day ";
		else cout << "failure on day ";
		cout << counter << endl;
	}
	system("pause");
	return 0;
}