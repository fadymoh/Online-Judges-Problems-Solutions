#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, n, x, y, pop;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int arr[5][5] = {0};
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			cin >> arr[x][y];
		}
		int minn = 10000000;
		int off1, off2, off3, off4, off5;

		for (int i = 0; i < 25; ++i) { //office 1
			for (int j = i + 1; j < 25; ++j) { //office 2
				for (int k = j + 1; k < 25; ++k) { //office 3
					for (int q = k + 1; q < 25; ++q) { // office 4
						for (int e = q + 1; e < 25; ++e) { //office 5
							int t1, t2, t3, t4, t5;
							int sum = 0;
							for (int x = 0; x < 5; x++) {
								for (int y = 0; y < 5; y++) {
									t1 = arr[x][y] * (abs(x - i / 5) + abs(y - i % 5));
									t2 = arr[x][y] * (abs(x - k / 5) + abs(y - k % 5));
									t3 = arr[x][y] * (abs(x - j / 5) + abs(y - j % 5));
									t4 = arr[x][y] * (abs(x - q / 5) + abs(y - q % 5));
									t5 = arr[x][y] * (abs(x - e / 5) + abs(y - e % 5));

									sum += min(t1, min(t2, min(t3, min(t4, t5))));
								}
							}
							if (sum < minn)
							{
								off1 = i;
								off2 = j;
								off3 = k;
								off4 = q;
								off5 = e;
								minn = sum;
							}
						}
					}
				}
			}
		}
		cout << off1 << ' ' << off2 << ' ' << off3 << ' ' << off4 << ' ' << off5 << '\n';
	}
	system("pause");
	return 0;
}