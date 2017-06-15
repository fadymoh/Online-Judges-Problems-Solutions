#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct mystruct{
	int x_cord, y_cord;
};
int main()
{
	
	int m;
	string input;
	while (cin >> m){
		vector<mystruct> three, ones;
		mystruct x;
		for (int i = 0; i < m; i++){
			cin >> input;
			for (int j = 0; j < m; j++){
				if (input[j] == '1') { x.x_cord = j, x.y_cord = i; ones.push_back(x); }
				else if (input[j] == '3') { x.x_cord = j, x.y_cord = i; three.push_back(x); }
			}
		}
		int max_path = 0;
		for (int i = 0; i < ones.size(); i++){
			int max = 10000;
			for (int j = 0; j < three.size(); j++){
				int temp = abs(ones[i].x_cord - three[j].x_cord) + abs(ones[i].y_cord - three[j].y_cord);
				if (temp < max) max = temp;
			}
			if (max_path < max) max_path = max;
		}
		cout << max_path << endl;
	}
	system("pause");
	return 0;
}