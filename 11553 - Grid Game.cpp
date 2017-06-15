#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int T,n, val;
	cin >> T;

	while (T--){
		cin >> n;
		int arr[8][8] = {0};
		int colOrder[8] = {0};
		for (int x = 0; x < n; x++){
			for (int y = 0; y < n; y++){
				cin >> val;
				arr[x][y] = val;
			}
		}
		for (int i = 0; i < n; i++){
			colOrder[i] = i;
		}
		int smallest = 10000000;
		do {
			int total = 0;
			for (int i = 0; i < n; i++)
			{
				int temp = arr[i][colOrder[i]];
				total += temp;
			}
			if (total < smallest) smallest = total;
		} while (next_permutation(colOrder, colOrder + n));
		cout << smallest << endl;

	}

	system("pause");
	return 0;
}