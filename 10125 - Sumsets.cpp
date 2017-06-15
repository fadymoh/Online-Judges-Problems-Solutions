#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
bool find(vector<int>myvector, int& d)
{
	for (int s = myvector.size() - 1; s>= 0; --s){
		for (int i = 0; i < myvector.size(); ++i){
			for (int j = i + 1; j < myvector.size(); ++j){
				for (int k = j + 1; k < myvector.size(); ++k){
					long long temp = myvector[i] + myvector[j] + myvector[k];
					if (myvector[s] == temp)
						if ( i != s && j != s && k != s){
						{ 
								d = myvector[s];
								return true;
						}
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	
	int n, d, x;
	cin >> n;
	while (n != 0){
		vector <int> myvector;
		for (int i = 0; i < n; i++){
			cin >> x;
			myvector.push_back(x);
		}
		sort(myvector.begin(), myvector.end());
		if (!find(myvector, d)) cout << "no solution" << endl;
		else
			cout << d << endl;
		cin >> n;
	}
	system("pause");
	return 0;
}