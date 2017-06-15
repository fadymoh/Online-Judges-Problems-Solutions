#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int f, r;
	double x;
	
	cin >> f;
	while (f != 0){
		cin >> r;
		vector<double> front, rear, drive;

		for (int i = 0; i < f; i++){
			cin >> x;
			front.push_back(x);
		}
		for (int i = 0; i < r; i++){
			cin >> x;
			rear.push_back(x);
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < f; j++){
				drive.push_back(rear[i] / front[j]);
			}
		}
		sort(drive.begin(), drive.end());
		double max = 0;
		for (int i = 0; i < drive.size() - 1; i++){
			double temp = drive[i + 1] / drive[i];
				if (temp> max) max = temp;
		}
		cout << fixed << setprecision(2) << max << endl;
		cin >> f;
	}




	system("pause");
	return 0;
}