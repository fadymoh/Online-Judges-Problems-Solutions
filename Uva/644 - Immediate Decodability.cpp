#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int set_c = 0;
	string x;
	while (true)
	{
		cin >> x;
		vector<string> mVector;
		if (cin.eof()) break;
		else mVector.push_back(x);
		while (cin >> x, x != "9")
		{
			mVector.push_back(x);
		}
		bool flag = true;
		for (int i = 0; i < mVector.size(); ++i)
		{
			for (int j = 0; j < mVector.size(); ++j)
				if (i != j && mVector[i].size() <= mVector[j].size())
				{
					if (mVector[j].substr(0, mVector[i].size()) == mVector[i])
						flag = false;
				}
		}
		if (flag) cout << "Set " << ++set_c << " is immediately decodable\n";
		else cout << "Set " << ++set_c << " is not immediately decodable\n";
	}
	return 0;
}