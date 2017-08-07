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

int main()
{
	int n;
	do {
		scanf("%d", &n);
		if (n == 0) break;
		int x;
		bool flag = false;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (x){ if (!flag) { printf("%d", x); flag = true; } else printf(" %d", x); }
		}
		if (!flag) printf("0");
		printf("\n");
	} while (true);
	system("pause");
	return 0;
}