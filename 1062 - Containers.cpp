#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{	
	string temp;
	int case_counter = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (getline(cin, temp), temp != "end")
	{
		vector <stack <char>> mVector;
		bool flag = false;
		for (int s = 0; s < temp.length(); ++s)
		{
			flag = false;
			for (int i = 0; i < mVector.size(); ++i)
			{
				if (mVector[i].size())
				{
					if (mVector[i].top() >= temp[s])
					{
						flag = true;
						mVector[i].push(temp[s]);
						break;
					}
				}
			}
			if (!flag)
			{
				stack <char> mStack;
				mStack.push(temp[s]);
				mVector.push_back(mStack);
			}
		}
		cout << "Case " << ++case_counter << ": " << mVector.size() << endl;
	}
	system("pause");
	return 0;
}