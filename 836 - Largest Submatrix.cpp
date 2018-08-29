#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	string s;
	getline(cin, s);
	while (tc--)
	{
		int n = 0, arr[26][26] = { 0 };
		int rows = 0;
		while (getline(cin, s) && s != "")
		{
			for (int i = 0; i < s.length(); ++i)
			{
				arr[rows][i] = ((s[i] - '0') ? 1: -10000);
			}

			rows++;
		}

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < rows; ++j)
			{
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}
		int maxx = 0;

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < rows; ++j)
				for (int x = i; x < rows; ++x)
					for (int y = j; y < rows; ++y)
					{
						int sub = arr[x][y];
						if (i > 0) sub -= arr[i - 1][y];
						if (j > 0) sub -= arr[x][j - 1];
						if (i > 0 && j > 0) sub += arr[i - 1][j - 1];
						maxx = max(maxx, sub);
					}
		cout << maxx << endl;
		if (tc) cout << endl;
	}
	system("pause");
	return 0;
}