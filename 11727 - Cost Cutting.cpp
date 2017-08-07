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
	int TC, CC = 1;
	cin >> TC;
	while (TC--){
		vector <int> myvector(3);
		cin >> myvector[0] >> myvector[1] >> myvector[2];
		sort(myvector.begin(), myvector.end());
		cout << "Case " << CC++ << ": " <<myvector[1] << endl;
	}
	system("pause");
	return 0;
}
