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
	float duration, down_payment, amount_of_loan, depreciation, total;
	while (cin >> duration >> down_payment >> amount_of_loan >> depreciation, duration > 0){
		total = down_payment + amount_of_loan;
		vector<float> myvector(duration+1);
		while (depreciation--)
		{
			int month;
			float depreciationn;
			cin >> month >> depreciationn;
			for (int i = month; i <= duration; ++i)
				myvector[i] = depreciationn;
		}
		int counter = 0;
		int month_counter = 1;
		bool flag = true;
		down_payment = amount_of_loan / duration;
		total = total - (total*myvector[0]);
		while (amount_of_loan > total && counter <= duration)
		{
			amount_of_loan -= down_payment;
			total = total - (total * (myvector[month_counter++]));
			counter++;
		}
		
		cout << counter;
		if (counter == 1) cout << " month";
		else cout << " months";
		cout << endl;
	}
	system("pause");
	return 0;
}