#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int T, areas, x,y, population;
	cin >> T;
	while (T--){
		cin >> areas;
		int arr[5][5] = { 0 }, offices[5] = { 0, 1, 2, 3, 4 }, mini = 1000000;
		for (int i = 0; i < areas; i++){
			cin >> x >> y >> population;
			arr[x][y] = population;
		}

		for (int i = 0; i < 25; i++){
			for (int k = i + 1; k < 25; k++){
				for (int j = k + 1; j < 25; j++){
					for (int q = j + 1; q < 25; q++){
						for (int e = q + 1; e < 25; e++){
							int t1, t2, t3, t4, t5;
							int sum = 0;
							for (int x = 0; x < 5; x++){
								for (int y = 0; y < 5; y++){
									t1 = arr[x][y] * (abs(x - i / 5) + abs(y - i % 5));
									t2 = arr[x][y] * (abs(x - k / 5) + abs(y - k % 5));
									t3 = arr[x][y] * (abs(x - j / 5) + abs(y - j % 5));
									t4 = arr[x][y] * (abs(x - q / 5) + abs(y - q % 5));
									t5 = arr[x][y] * (abs(x - e / 5) + abs(y - e % 5));

									sum += min(t1, min(t2, min(t3, min(t4, t5))));
								}
							}
							if (sum < mini) {
								offices[0] = i;
								offices[1] = k;
								offices[2] = j;
								offices[3] = q;
								offices[4] = e;
								mini = sum;
							}
						}
					}
				}
			}
		}
		cout << offices[0] << " " <<  offices[1] << " " <<  offices[2] << " "  <<  offices[3]  << " " << offices[4] << endl;
	}
	system("pause");
	return 0;
}