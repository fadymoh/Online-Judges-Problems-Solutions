#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
using namespace std;
int counter = 0, n;
int combinations[20];
bool arr[20];

bool is_prime(int p) {
	for (int i = 2; i <= sqrt(p); i++)
	if (p % i == 0) return false;
	return true;
}
void backtrack(int m)
{
	if (m == n-1 && (is_prime(combinations[n - 1] + combinations[n]))){
		for (int i = 0; i < n; i++)  printf(i == n - 1 ? "%d" : "%d ", combinations[i]);
		cout << endl;
		return;
	}
	for (int i = 2; i <= n; i++){
		if (!arr[i] && is_prime(combinations[m]+i)){
			arr[i] = true;
			combinations[m + 1] = i;
			backtrack(m + 1);
			arr[i] = false;
		}
	}
}

int main()
{
	while (cin >> n){
		counter++;
		for (int i = 0; i < 20; i++) arr[i] = 0;
		if (counter > 1) cout << endl;
		printf("Case %d:\n", counter);
		combinations[0] = combinations[n] = 1;
		backtrack(0);
	}
	system("pause");
	return 0;
}