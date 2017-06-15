#include <iostream>
#include<cmath>
#include<cstdio>
#include <vector>
using namespace std;


int main()
{
	int cases, d , T , x , k;
	cin >> cases;
	while (cases--){
		vector<int> coeff;
		cin >> T;
		T++;
		for (int i = 0; i < T; i++){
			cin >> x;
			coeff.push_back(x);
		}
		cin >> d >> k;
		int sum = 0;
		long long answer = 0;
		for (int n = 1; n <= k; n++){
			sum += n*d;
			if (sum >= k){
				for (int j = 0; j < coeff.size(); j++){
					answer += coeff[j] * pow(n, j);	
				}
				cout << answer << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}
