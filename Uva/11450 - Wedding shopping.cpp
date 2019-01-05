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
int price[25][25], memo[210][25], m, c;
int shop(int money, int g)
{
	if (money < 0) return -10000;
	if (g == c) return m - money;
	int &ans = memo[money][g];
	if (ans != -1) return ans ;
	for (int i = 1; i <= price[g][0]; i++)
		ans = max(ans, shop(money-price[g][i],g+1));
	return ans;
}
int main()
{
	int TC, k;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &m, &c);
		for (int i = 0; i < c; i++){
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof memo);
		int ans = shop(m, 0);
		if (ans < 0)printf("no solution\n");
		else printf("%d\n", ans);
	}
	system("pause");
	return 0;
}

