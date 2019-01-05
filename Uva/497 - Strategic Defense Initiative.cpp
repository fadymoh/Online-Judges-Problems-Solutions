#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> printing;
vector<int> mVector;
vector<int> lis;
void print(int i)
{
	if (i != -1)
		print(printing[i]), printf("%d\n", mVector[i]);
}
int main()
{
	int tc;
	string s;
	cin >> tc;
	cin.ignore();
	getline(cin, s);
	while (tc--)
	{

		while (getline(cin, s) && s != "") mVector.push_back(stoi(s));

		for (int i = 0; i < mVector.size(); ++i)
		{
			int x = mVector[i];
			int ans_lis = 0, ans_pos = -1;
			for (int j = i - 1; j >= 0; --j)
				if (mVector[j] < x && lis[j] > ans_lis)
					ans_lis = lis[j], ans_pos = j;
			lis.push_back(ans_lis + 1);
			printing.push_back(ans_pos);
		}
		int ans_lis = 0, ans_pos = -1;
		for (int i = 0; i < mVector.size(); ++i)
		{
			if (lis[i] > ans_lis)
				ans_lis = lis[i], ans_pos = i;
		}
		cout << "Max hits: " << ans_lis << endl;
		print(ans_pos);
		printing.clear();
		mVector.clear();
		lis.clear();
		if (tc) cout << endl;
	}
	system("pause");
	return 0;
}