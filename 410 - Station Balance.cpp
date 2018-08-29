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
	int C, S, set = 0;
	while (scanf("%d %d", &C, &S) != EOF) {
		vector <int> specimen(2 * C);
		specimen.assign(2 * C, 0);
		double avg = 0.0;
		for (int i = 0; i < S; i++)
		{
			cin >> specimen[i];
			avg += specimen[i];
		}
		avg /= C;
		sort(specimen.begin(), specimen.end());
		double ans = 0.0;
		printf("Set #%d\n", ++set);
		for (int i = 0; i < C; i++){
			printf("%2d:", i);
			int val1 = specimen[i], val2 = specimen[2 * C - i - 1];

				if (val2)cout << " " <<val2;
				if (val1) cout << " " << val2;
				ans += fabs((val1 + val2 - avg));
				cout << endl;
		}
		printf("IMBALANCE = %.5lf\n\n", ans);
	}

	system("pause");
	return 0;
}

