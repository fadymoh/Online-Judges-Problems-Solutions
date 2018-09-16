#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	string in;
	while (getline(cin, in)) {
		stringstream ss(in);
		string token;
		vector <int> mVector;
		int arr[10000001] = {0};
		bool flag = true;
		while (ss >> token)
		{
			int temp = stoi(token);
			if (temp < 0) {
				mVector.push_back(abs(temp));
			}
			else if (!mVector.empty() && mVector.back() == temp)
			{
				arr[mVector.back()] = 0;
				mVector.pop_back();
				if (!mVector.empty())arr[mVector.back()] += temp;
				if (!mVector.empty() && arr[mVector.back()] >= mVector.back())
				{
					flag = false;
					break;
				}
				if (!mVector.empty() && mVector.back() <= temp) {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag && mVector.empty()) cout << ":-) Matrioshka!\n";
		else cout << ":-( Try again.\n";
	}
	return 0;
}