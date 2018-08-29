#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int num_of_lines;
	cin >> num_of_lines;
	int max = -1;
	do{
		char liness[30];
		gets(liness);
		int number_of_xs[20] = { 0 };
		for (int i = 0; i < num_of_lines; i++){
			gets(liness);
			for (int j = 0; liness[j]; j++)
					if (liness[j] == 'X') number_of_xs[i]++;
			if (number_of_xs[i]>max)
				max = number_of_xs[i];
		}
		int	output_counter = 0;
		for (int i = 0; i < num_of_lines; i++)
			output_counter += (max - number_of_xs[i]);
		cout << output_counter << endl;
		max = -1;
		cin >> num_of_lines;
	} while (num_of_lines != 0);
	system("pause");
	return 0;
}