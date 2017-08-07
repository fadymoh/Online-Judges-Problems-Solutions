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

int main()
{
	int TC, n, x, cases = 0;
	cin >> TC;
	while (TC--){
		cin >> n;
		int ans = 0, sum = 0, initial = 0, end = 0, tmp = 1;
		for (int i = 2; i <= n; i++){
			cin >> x;
			sum += x;
			if (sum < 0) sum = 0, tmp = i;
			if (sum >= ans){
				if (sum > ans || sum == ans && (i - tmp > end - initial)){
					initial = tmp;
					end = i;
				}
				ans = sum;
			}
		}
		if (ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n", ++cases, initial, end);
		else
			printf("Route %d has no nice parts\n", ++cases);
	}

	system("pause");
	return 0;
}