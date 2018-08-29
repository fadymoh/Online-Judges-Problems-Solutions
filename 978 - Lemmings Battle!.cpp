#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool opr(const int& one, const int& two)
{
	return one > two;
}
int main()
{
	int n;
	cin >> n;
	for (int t = 0; t< n; ++t)
	{
		if (t > 0)
			cout << endl;
		int battlefields, green, blue, temp;
		multiset<int> mGreen, mBlue;
		cin >> battlefields >> green >> blue;
		for (int i = 0; i < green; ++i)
		{
			cin >> temp;
			mGreen.insert(temp);
		}
		for (int i = 0; i < blue; ++i)
		{
			cin >> temp;
			mBlue.insert(temp);
		}
	
		while (!mGreen.empty() && !mBlue.empty()) {
			int no_fights = min(battlefields, (int)mBlue.size());
				no_fights = min(no_fights,(int) mGreen.size());
				vector<int> save_green, save_blue;
			for (int i = 0; i < no_fights; ++i)
			{
				auto blue = mBlue.end();
				auto green = mGreen.end();
				blue--;
				green--;
				int green_fighter = *green, blue_fighter = *blue;
				mGreen.erase(green);
				mBlue.erase(blue);
				if (green_fighter > blue_fighter)
					save_green.push_back(green_fighter - blue_fighter);
				else if (blue_fighter > green_fighter)
					save_blue.push_back(blue_fighter - green_fighter);	
			}
			for (auto x : save_green) mGreen.insert(x);
			for (auto x : save_blue) mBlue.insert(x);
		}

		if (mGreen.empty() && mBlue.empty())
		{
			cout << "green and blue died" << endl;
		}
		else if (mGreen.empty())
		{
			cout << "blue wins\n";
			
			for (auto x = mBlue.rbegin(); x != mBlue.rend(); ++x)
				cout << *x << endl;
		}
		else
		{
			cout << "green wins\n";
			for (auto x = mGreen.rbegin(); x != mGreen.rend(); ++x)
				cout << *x << endl;;
		}
	}
	system("pause");
	return 0;
}