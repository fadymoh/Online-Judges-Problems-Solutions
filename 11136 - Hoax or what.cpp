#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
vector<string> split(const char *str, char c = ' ')
{
	vector<string> result;
	do{
		const char *begin = str;
		while (*str != c && *str)
			str++;
		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}
int main()
{
	int n;

	while (cin >> n, n != 0)
	{
		int bills, temp;
		multiset<int> mSet;
		long long counter = 0;
		for (int t = 0; t < n; ++t)
		{
			cin >> bills;
			for (int i = 0; i < bills; ++i)
			{
				cin >> temp;
				mSet.insert(temp);
			}
			auto largest = mSet.end();
			auto smallest = mSet.begin();
			largest--;
			counter += (*largest - *smallest);
			mSet.erase(largest);
			mSet.erase(smallest);
		}
		cout << counter << endl;
	}
	system("pause");
	return 0;
}