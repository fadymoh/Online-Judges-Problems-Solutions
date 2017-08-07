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
	int TC, n, Case_counter = 0;
	cin >> TC;
	char buffer[101];
	while (TC--){
		cin >> n >> buffer;
		cout << "Case " << ++Case_counter << ": ";
		int idx = 1, ScareCrows = 0;
		for (int i = 0; i < n; i++){
			if (buffer[i] == '.'){
				ScareCrows++;
				buffer[i] = buffer[i + 1] = buffer[i + 2] = '#';
				i += 2;
			}
		}
		cout << ScareCrows << endl;
	}
	system("pause");
	return 0;
}

