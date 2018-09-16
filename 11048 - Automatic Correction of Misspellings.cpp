#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define Correct 1
#define incorrect 2
#define missing_letter 3
#define extra_letter 4
#define unknown 0
int main()
{
	int n, p;
	string temp;
	cin >> n;
	vector<vector<string>> arr(26);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		arr[temp.size()].push_back(temp);
	}
	cin >> p;
	for (int i = 0; i < p; ++i)
	{
		cin >> temp;
		int size = temp.size();
		int k;
		int flag = unknown;
		int save = -1;
		for (k = 0; k < arr[size].size(); ++k)
		{
			int counter = 0;
			int initial = -1;
			for (int j = 0; j < arr[size][k].size(); ++j)
				if (arr[size][k][j] != temp[j]) {
					if (initial == -1) initial = j;
					++counter;
				}
			if (counter == 0) {
				flag = Correct;
				break;
			}
			else if (counter == 1) {
				flag = incorrect;
				if (save == -1) save = k;
			}
			else if (counter == 2) {
				string x = temp;
				reverse(x.begin() + initial, x.begin() + initial + 2);
				if (x == arr[size][k]) {
					flag = incorrect;
					if (save == -1) save = k;
				}
			}
		}

		if (flag == Correct) cout << temp << " is correct\n";
		else if (flag == incorrect) cout << temp << " is a misspelling of " << arr[size][save] << endl;
		else {
			int size = temp.size();
			int k;
			for ( k = 0; k < arr[size - 1].size(); ++k)
			{
				int counter = 0;
				int save = -1;
				for (int j = 0; j < arr[size-1][k].size(); ++j)
					if (arr[size-1][k][j] != temp[j]) {
						save = j;
						break;
					}
				if (temp.substr(0, save) == arr[size - 1][k].substr(0, save)
					&& temp.substr(save + 1) == arr[size - 1][k].substr(save))
				{
					flag = incorrect;
					break;
				}
			}
			if (flag == incorrect) cout << temp << " is a misspelling of " << arr[size - 1][k] << endl;
			else if (size + 1 <= 24)
			{
				int k;
				for (k = 0; k < arr[size + 1].size(); ++k)
				{
					int counter = 0;
					int save = -1;
					for (int j = 0; j < size; ++j)
						if (arr[size + 1][k][j] != temp[j]) {
							++counter;
							save = j;
							break;
						}
					if (counter == 0) {
						flag = incorrect;
						break;
					}
					else if (temp.substr(0, save) == arr[size + 1][k].substr(0, save)
						&& temp.substr(save) == arr[size + 1][k].substr(save+1))
					{
						flag = incorrect;
						break;
					}
				}
				if (flag == incorrect) cout << temp << " is a mispelling of " << arr[size + 1][k] << endl;
				else
					cout << temp << " is unknown" << endl;
			}
			else cout << temp << " is unknown" << endl;
		}

	}
	return 0;
}