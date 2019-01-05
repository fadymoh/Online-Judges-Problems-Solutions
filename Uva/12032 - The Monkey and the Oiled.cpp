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
vector <int> myvector;
int n;
bool can_reach(int k)
{
	int mystep = 0;
	for (int i = 0; i < n; i++){
	//	if (k == 0) return false;
		if (myvector[i] - mystep > k) return false;
		else if (myvector[i] - mystep == k) k--;
		mystep = myvector[i];
	}
	return true;
}
int main()
{
	int TC, case_counter = 1;
	cin >> TC;
	while (TC--){
		cin >> n;
		myvector.clear();
		myvector.resize(n);
		
		for (int i = 0; i < n; i++)
			cin >> myvector[i];
		
		int L = 0, U = 100000000, ans = 0;
		while (L <= U){
			int mid = (L + U) / 2;
			if (can_reach(mid)){
				ans = mid;
				U = mid - 1;
			}
			else
				L = mid + 1;
		}
		cout << "Case " << case_counter++ << ": " << ans << endl;
	}
	system("pause");
	return 0;
}

