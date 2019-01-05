#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> combinations, people;
	int val;
	for (int i = 0; i <= 20; i++)
		for (int j = 1; j <= 3; j++)
			combinations.push_back(i*j);
		combinations.push_back(50);
		cin >> val;
	while (val > 0){
		people.push_back(val);
		cin >> val;
	}
	sort(combinations.begin(), combinations.end());
	auto e = unique(combinations.begin(), combinations.end());
	combinations.resize(e - combinations.begin());
	while (!people.empty()){
		int temp = people[0];
		int counter = 0, index = 0, comb = 0, perm = 0;
		people.erase(people.begin());
		for (int i = 0; i < combinations.size(); i++)
			for (int j = i; j < combinations.size(); j++)
			for (int x = j; x < combinations.size(); x++)
			{
				if (combinations[i] + combinations[j] + combinations[x] == temp)
					comb++;
			}
			for (int i = 0; i < combinations.size(); i++)
			for (int j = 0; j < combinations.size(); j++)
			for (int x = 0; x < combinations.size(); x++)
			if (combinations[i] + combinations[j] + combinations[x] == temp)
				perm++;
			if (comb)
				printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", temp, comb, temp, perm);
			else
				printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", temp);
			for (int i = 0; i < 70; i++) putchar('*');
			putchar('\n');
	}
	printf("END OF OUTPUT\n");
	system("pause");
	return 0;
}