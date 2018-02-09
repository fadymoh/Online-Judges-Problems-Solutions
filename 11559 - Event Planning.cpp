#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
int main()
{
	int participants, budget, hotels, weeks;
	while (scanf_s("%d %d %d %d", &participants, &budget, &hotels, &weeks) == 4){
		int i, price_per_stay, j, beds, minn = 5000000;
		rep(i, 1, hotels){
			cin >> price_per_stay;
			int temp = 0;
			rep(j, 1, weeks){
				cin >> beds;
				if (beds >= participants)
					temp = 1;
			}
			if (temp) minn = min(minn, participants*price_per_stay);
		}
		(minn > budget) ? cout << "stay home" : cout << minn;
		cout << endl;
	}

	system("pause");
	return 0;
}
