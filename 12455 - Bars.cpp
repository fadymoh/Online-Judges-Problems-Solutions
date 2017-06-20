#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
int n, p, sum;
bool flag;
bool used[21];
vector <int> bars;
void backtrack(int x){
	if (sum == n) {
		flag = true;
		return;
	}
	if (x == p || sum > n) return;

	for (int i = x; i < p; i++){
		if (!used[i]){
			if (bars[i] <= n - sum){
				used[i] = true;
				sum += bars[i];
				backtrack(x + 1);
				used[i] = false;
				sum -= bars[i];
			}
		}
	}
}
int main()
{
	int TC;
	cin >> TC;
	while (TC--){
		cin >> n >> p;
		sum = 0;
		bars.clear();
		bars.resize(p);
		memset(used, false, sizeof used);
		flag = false;
		for (int i = 0; i < p; i++)
			cin >> bars[i];
		backtrack(0);
		flag ? printf("YES\n") : printf("NO\n");
	}
	system("pause");
	return 0;
}



