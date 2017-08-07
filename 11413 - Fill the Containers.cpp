#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <iomanip>
using namespace std;
vector <int> vessels;
int m;
bool can_fill_it(int capacity)
{
	int number_containers = 1, C = capacity;
	for (int i = 0; i < vessels.size(); i++){
		if (vessels[i] > capacity) return false;

		if (vessels[i] > C){
			if (number_containers == m) return false;
			++number_containers;
			C = capacity;
		}
		C -= vessels[i];
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n >> m){
		vessels.clear();
		vessels.resize(n);
		for (int i = 0; i < n; i++)
			cin >> vessels[i];
		int U = 1000000000, L = 1, mid, capacity = 0;
		while (L <= U){
			mid = (L + U) / 2;
			if (can_fill_it(mid)){
				capacity = mid;
				U = mid - 1;
			}
			else
				L = mid + 1;
		}
		cout << capacity << endl;
	}



	system("pause");
	return 0;
}