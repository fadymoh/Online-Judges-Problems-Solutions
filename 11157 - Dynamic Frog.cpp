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
struct mystruct{
	char type = 'B';
	int distance = 0;
	bool jumped = false;
};
int main()
{
	int TC, n, d, case_counter = 0;
	scanf_s("%d", &TC);
	while (TC--){
		cin >> n >> d;
		char sep;
		vector <mystruct> myvector(n+20);
		for (int i = 0; i < n; ++i)
			cin >> myvector[i].type >> sep >> myvector[i].distance;
		myvector[n].distance = d;
		int maxx = myvector[0].distance;
		for (int i = 0; i < n; i++){
			myvector[i].jumped = true;
			if (myvector[i+1].type == 'S'){
				maxx = max(maxx, myvector[i + 2].distance - myvector[i].distance);
				++i;
			}
			else{
				maxx = max(maxx, myvector[i + 1].distance - myvector[i].distance);
			}
		}
		for (int i = n; i > 0; --i){
			if (!myvector[i-1].jumped || myvector[i-1].type == 'B'){
				maxx = max(maxx, myvector[i].distance - myvector[i - 1].distance);
			}
			else{
				if (i!= 1)
				maxx = max(maxx, myvector[i].distance - myvector[i - 2].distance);
				else
					maxx = max(maxx, myvector[i].distance);
				--i;
			}
		}
		cout << "Case " << ++case_counter << ": " << maxx << endl;
	}
	system("pause");
	return 0;
}


