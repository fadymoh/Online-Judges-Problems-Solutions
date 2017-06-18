#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
int row[8], x, y, lineCounter, queens[8];
bool check(int r, int c)
{
	for (int i = 0; i < r; i++)
	if (row[i] == c || abs(r - i) == abs(c - row[i])) return false;
	return true;
}
int backtrack(int n){
	if (n == 8) return 0;
	int tot = 100000;
	for (int i = 0; i < 8; i++)
		if (check(n, i)) { 
			row[n] = i; 
			tot = min(tot, i == queens[n] ? backtrack(n + 1) : 1 + backtrack(n + 1));
		}
	return tot;

}
int main()
{
	int T;
	
		for (int T = 1;; T++) {
			for (int i = 0; i < 8; i++) {
				if (scanf("%d", &queens[i]) == -1) return 0;
				queens[i]--; row[i] = queens[i];
			}

			printf("Case %d: %d\n", T, backtrack(0));
		}
	
	system("pause");
	return 0;
}