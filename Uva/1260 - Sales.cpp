#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int T, n, x;
	
	cin >> T;
	while (T--){
		cin >> n;
		vector <int> myvector;
		int b = 0;
		for (int i = 0; i < n; i++){
			cin >> x;
			myvector.push_back(x);
		}
		for (int i = 1; i < myvector.size(); i++){
			int counter = 0;
			for (int j = 0; j < i; j++){
				if (myvector[j] <= myvector[i])
					counter++;
			}
			b += counter;
		}
		cout << b << endl;
	}
	system("pause");
	return 0;
}