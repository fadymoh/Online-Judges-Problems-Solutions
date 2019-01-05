#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int number_of_froshs;
	cin >> number_of_froshs;
	do {
		map <vector<int>, int> mymap;
		mymap.clear();
		int unique_courses = 0;
		if (number_of_froshs == 0) break;
		while (number_of_froshs != 0){
			vector <int> myvector(5);
			for (int i = 0; i < 5; i++)
				cin >> myvector[i];
			sort(myvector.begin(), myvector.end());
			mymap[myvector]++;
			number_of_froshs--;
		}
		int maximum = -1;
		map<vector<int>, int>::iterator it = mymap.begin();
		while (it != mymap.end()){
			if (it->second == maximum) unique_courses += it->second;
			else if (it->second > maximum){
				maximum = it->second;
				unique_courses = it->second;
			}
			it++;
		}
		cout << unique_courses << endl;
		cin >> number_of_froshs;
	} while (true);
	system("pause");
	return 0;
}
