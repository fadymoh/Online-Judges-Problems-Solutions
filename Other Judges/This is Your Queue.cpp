#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
	int population, number_of_commands, number_of_person, temp, case_counter = 1;
	cin >> population >> number_of_commands;
	do {
		list <int> LL;
		if (population == 0 && number_of_commands == 0) break;
		population = min(population, 1000);
		cout << "Case " << case_counter++ << ":" << endl;
		for (int i = 1; i <= population; i++)
			LL.push_back(i);
		for (int i = 1; i <= number_of_commands; i++){
			char command_to_be_performed;
			cin >> command_to_be_performed;
			if (command_to_be_performed == 'N'){
				number_of_person = LL.front();
				cout << number_of_person << endl;
				LL.pop_front();
				LL.push_back(number_of_person);
			}
			else{
				cin >> number_of_person;
				LL.remove(number_of_person);
				LL.push_front(number_of_person);
			}
		}
		cin >> population >> number_of_commands;
	} while (true);
	system("pause");
	return 0;
}