#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct mystruct {

	vector<int> myvector;
	int myint, base_address;

};
int main()
{
	string name;
	int maximum_bound, base_address, size_of_element, num_of_arrays, num_of_references, index, address, num_of_dimensions, c0;
	vector<int> lower_bound, upper_bound, cD;

	map <string, mystruct> mymap;
	cin >> num_of_arrays >> num_of_references;

	for (int i = 1; i <= num_of_arrays; i++)
	{
		cin >> name >> base_address >> size_of_element >> num_of_dimensions;

		cD.resize(num_of_dimensions+ 1);
		lower_bound.resize(num_of_dimensions+1);
		upper_bound.resize(num_of_dimensions+1);

		index = num_of_dimensions - 1;
		c0 = base_address;
		cD[index] = size_of_element;

		for (int j = 0; j < num_of_dimensions; j++)
		{
			cin >> lower_bound[j] >> maximum_bound;
			upper_bound[j] = maximum_bound - lower_bound[j] + 1;
		}
		
		c0 -= cD[index] * lower_bound[index];

		index--;
		for (; index >= 0; --index)
		{
			cD[index] = cD[index + 1] * upper_bound[index+1];
			c0 -= cD[index] * lower_bound[index];
		}
		mymap[name].myvector = cD;
		mymap[name].myint = num_of_dimensions;
		mymap[name].base_address = c0;
		cD.clear();
	}
	for (int i = 1; i <= num_of_references; i++)
	{
		cin >> name;
		cout << name;
		string separator = "[";
		address = mymap[name].base_address;
		for (int j = 1; j <= mymap[name].myint; j++)
		{
			int value;
			cin >> value;
			cout << separator << value;
			separator = ", ";
			address += mymap[name].myvector[j-1] * value;
		}
		cout << "] = " << address << endl;
	}
	system("pause");
	return 0;
}