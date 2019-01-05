#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string in;
	cin >> in;
	string out;
	out = in;

	for (int i = 1; i < k; ++i)
	{
		int save = -1;
		for (int patternLength = 1; patternLength <= n-1; ++patternLength)
		{
			bool flag = false;
			int counter = 0;
			for (int j = patternLength-1; j >= 0; --j)
				if (out[out.length() - 1 - j] != in[counter++]) 
					flag = true;
			if (!flag) save = patternLength;
		}
		if (save == -1)
			out += in;
		else
			out += in.substr(save);
	}

	cout << out;
	system("pause");
	return 0;
}