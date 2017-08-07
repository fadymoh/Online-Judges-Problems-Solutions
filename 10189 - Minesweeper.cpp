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
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
int main()
{
	int n, m, i, j, CC = 1;
	cin >> n >> m;
	while (n){
		char mine[101][101], output[101][101];
		cout << "Field #" << CC++ << ":" << endl;
		rep(i, 0, n - 1) cin >> mine[i];

		rep(i, 0, n - 1){
			rep(j, 0, m - 1){
				if (mine[i][j] != '*'){
					int count = 0;
					for (int k = 0; k < 3; k++){
						for (int l = 0; l < 3; l++){
							int temp1 = i + k - 1, temp2 = j+l - 1;
							if (((temp1)<n) && ((temp2)<m)){
								if (((temp1)>-1) && ((temp2)>-1)){
									if ((mine[temp1][temp2] == '*') && !((temp1) == i && (temp2) == j)){
										count++;
									}
								}
							}
						}
					}
					output[i][j] = '0' + count;
				}
				else output[i][j] = '*';
			}
		}
		rep(i, 0, n - 1){
			rep(j, 0, m - 1)
				cout << output[i][j];
			cout << endl;
		}
		cin >> n >> m;
		if (n) cout << endl;
	}
	system("pause");
	return 0;
}