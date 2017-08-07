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
	int TC, n;
	cin >> TC;
	while (TC--){
		cin >> n;
		vector <int> coins(n);
		for (int i = 0; i < n; i++)
			cin >> coins[i];
		sort(coins.begin(), coins.end());
		int cointer = (n > 1) ? 2: 1, sum = 1;
		for (int i = 1; i < n - 1; i++){
			if (sum + coins[i] < coins[i + 1]){
				sum += coins[i];
				cointer++;
			}
		}
		cout << cointer << endl;
	}



	system("pause");
	return 0;
}

