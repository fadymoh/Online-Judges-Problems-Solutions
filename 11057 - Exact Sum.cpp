#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int numbers, sum;
	while (cin >> numbers){
		vector <int> price(numbers);
		for (int i = 0; i < numbers; i++)
			cin >> price[i];
		cin >> sum;
		sort(price.begin(), price.end());
		int s = 0, e = numbers - 1, m, i, j;
		while (s <= e){
			if (price[s] + price[e] == sum) { i = s; j = e; s++; e--; }
			else if (price[s] + price[e] > sum) e--;
			else s++;
		}
		cout << "Peter should buy books whose prices are " << price[i] << " and " << price[j] << ".\n\n";
	}
	system("pause");
	return 0;
}
