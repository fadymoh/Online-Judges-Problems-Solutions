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
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
int main()
{
	int TC;
	cin >> TC;
	for (int x = 0; x < TC; ++x)
	{
		int n, i, j, arr[200][200];
		cin >> n;
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < n; ++k){
				scanf("%d", &arr[j][k]);
				arr[j + n][k] = arr[j][k + n] = arr[j + n][k + n] = arr[j][k];
			}
		}

		for (int j = 0; j < 2 * n; ++j){
			for (int k = 0; k < 2 * n; ++k){
				if (j > 0) arr[j][k] += arr[j - 1][k];
				if (k > 0) arr[j][k] += arr[j][k - 1];
				if (j > 0 && k > 0) arr[j][k] -= arr[j - 1][k - 1];
			}
		}
		int maxx = -127 * 100 * 100;
		int subrect = maxx;
		rep(i, 0, n - 1) rep(j, 0, n - 1)
		for (int k = i; k < 2 * n && k < n + i; ++k) for (int l = j; l < 2 * n && l < n + j; ++l){

			subrect = arr[k][l];
			if (i > 0) subrect -= arr[i - 1][l];
			if (j > 0) subrect -= arr[k][j - 1];
			if (i > 0 && j > 0) subrect += arr[i - 1][j - 1];
			maxx = max(maxx, subrect);
		}

		cout << maxx << endl;
	}
	system("pause");
	return 0;
}
