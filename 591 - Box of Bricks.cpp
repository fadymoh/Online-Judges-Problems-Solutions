#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int number_of_set, height_of_towers, max = -1, number_of_moves = 0, set_counter = 1;
	vector <int> values;
	cin >> number_of_set;
	do {
		int sum_of_values = 0;
		values.resize(number_of_set + 1);
		for (int i = 0; i < number_of_set; i++){
			cin >> values[i];
			sum_of_values += values[i];
		}
		height_of_towers = sum_of_values / number_of_set;
		number_of_moves = 0;
		cout << "Set #" << set_counter << endl << "The minimum number of moves is " << number_of_moves << "." << endl << endl;
		cin >> number_of_set;
		values.clear();
		set_counter++;
	} while (number_of_set != 0);

	system("pause");
	return 0;
}