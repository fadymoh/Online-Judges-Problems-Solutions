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
	int n, i, j, arr[101][101];
	cin >> n;
	rep(i, 0, n - 1){
		rep(j, 0, n - 1){
			cin >> arr[i][j];
			if (i > 0) arr[i][j] += arr[i - 1][j];
			if (j > 0) arr[i][j] += arr[i][j - 1];
			if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j-1];
		}
	}
	int maxx = -127 * 100 * 100;
	int subrect = maxx;
	rep(i, 0, n - 1) rep(j, 0, n - 1)
	for (int k = i; k < 2 * n && k < n + i; ++k) for (int l = j; l < 2 * n && l < n + j; ++l){
	//rep(k, i, 2*n - 1) rep(l , j, 2*n - 1){
		 subrect = arr[k][l];
		if (i > 0) subrect -= arr[i - 1][l];
		if (j > 0) subrect -= arr[k][j - 1];
		if (i > 0 && j > 0) subrect += arr[i - 1][j - 1];
		maxx = max(maxx, subrect);
			}
		
	cout << maxx << endl;

	system("pause");
	return 0;
}
