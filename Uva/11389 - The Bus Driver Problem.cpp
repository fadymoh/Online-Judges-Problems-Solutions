#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n, d, r;
	do {
		cin >> n >> d >> r;
		if (n == 0 && d == 0 & r == 0)break;
		vector <int> morning(n);
		vector <int> evening(n);
		for (int i = 0; i < n; i++)
			cin >> morning[i];
		for (int i = 0; i < n; i++)
			cin >> evening[i];
		sort(morning.begin(), morning.end());
		sort(evening.begin(), evening.end());
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (morning[i] + evening[n - 1 - i] > d) ans += r*(morning[i]+evening[n-1-i]-d);
		}
		cout << ans << endl;
	} while (true);



	system("pause");
	return 0;
}
