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
	int m, n;
	while (cin >> m >> n, m){
		int ans = 0;
		if (m == 1 || n == 1)
			ans = m * n;
		
		else if (m == 2 || n == 2){
			int k, c, d;
			(m == 2) ? k = n : k = m;
			c = (k % 4 == 0) ? k / 4 : (k / 4) + 1;
			d = ((k - 1) % 4 == 0) ? (k - 1) / 4 : ((k - 1) / 4) + 1;
			ans = 2 * (c + d);
		}
		else 
			ans =((m*n) % 2 == 0) ? (m*n) / 2 : ((m*n) / 2) + 1;
		cout << ans << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	}


	system("pause");
	return 0;
}

