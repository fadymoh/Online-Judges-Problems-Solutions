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
	int b, s, case_counter = 0;
	while (cin >> b >> s){
		if (b == 0 && s == 0) break;
		vector <int> bachelor(b);
		vector <int> spinser(s);
		bool used[10000] = { 0 };
		for (int i = 0; i < b; i++)
			scanf("%d", bachelor[i]);
		for (int i = 0; i < s; i++)
			scanf("%d", spinser[i]);
		sort(bachelor.begin(), bachelor.end());
		cout << "Case " << ++case_counter << ": ";
		if (b <= s)
			printf("Case %d: 0\n", ++case_counter);
		else
			printf("Case %d: %d %d\n", ++case_counter, b-s, bachelor[0]);
	}
	system("pause");
	return 0;
}
