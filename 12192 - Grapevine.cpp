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
	int rows, cols, Q, L, U;
	do {
		cin >> rows >> cols;
		if (rows == 0 && cols == 0) break;
		int arr[501][501] = { 0 };
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++){
			cin >> arr[i][j];
		}
		cin >> Q;
		for (int i = 0; i < Q; i++){
			cin >> L >> U;
			int max = 0;
			for (int j = 0; j < rows; j++){
				int* lower = lower_bound(arr[j], arr[j] + cols, L);
				int idx = lower - arr[j];
				for (int k = max; k < rows; k++){
					if (k + j >= rows || k + idx >= cols || arr[j + k][k + idx] > U) break;
					if (k + 1> max) max = k + 1;
				}
				
			}
			printf("%d\n", max);
			
		}
		printf("-\n");
	} while (true);


	system("pause");
	return 0;
}

