#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct myObj {
	string title, author, whole;
	bool borrowed = false;
	int index;
	bool operator == (const myObj& two) {
		return (this->author == two.author && this->title == two.title);
	}
};
bool opr (const myObj& first, const myObj& second)
{
	return (first.whole < second.whole);
}

int main()
{
	string delimiter = string(1, '"');
	vector<myObj> myVector;
	bool flag_global = false;
	while (true)
	{
		myObj temp;
		string whole;
		getline(cin, whole);
		if (whole == "END")
			break;
		int found = whole.find(delimiter, 1);
		temp.title = whole.substr(1, found-1);
		temp.author = whole.substr(found + 5);
		temp.whole = temp.author + '_' + temp.title;
		temp.borrowed = false;
		myVector.push_back(temp);
	}
	sort(myVector.begin(), myVector.end(), opr);
	vector<myObj> borrow;
	while (true)
	{
		string temp;
		getline(cin, temp);
		if (temp == "END")
			break;
		if (temp[0] == 'R') {
			int found = temp.find('"');
			string sub = temp.substr(found + 1, temp.length() - 9);
			int i;
			for (i = 0; i < myVector.size(); ++i)
			{
				if (myVector[i].title == sub)
				{
					myVector[i].index = i;
					borrow.push_back(myVector[i]);
					flag_global = true;
					break;
				}
			}
		}
		else if (temp[0] == 'B') {
			int found = temp.find('"');
			int found2 = temp.find(found + 1, '"');
			string sub = temp.substr(found + 1, temp.length() - 9);
			for (int i = 0; i < myVector.size(); ++i)
			{
				if (myVector[i].title == sub)
				{
					myVector[i].borrowed = true;
				}
			}
		}
		else if (temp[0] == 'S')
		{
			sort(borrow.begin(), borrow.end(), opr);
			for (int i = 0; i < borrow.size(); ++i)
			{
				if (flag_global)
					if (borrow[i].index == 0)
					{
						cout << "Put " << '"' << borrow[i].title << '"' << " first" << endl;
						myVector[0].borrowed = false;
					}
				else
				{
					bool flag = false;
					for (int j = borrow[i].index - 1; j >= 0; --j)
						if (!myVector[j].borrowed)
						{
							myVector[borrow[i].index].borrowed = false;
							flag = true;
							cout << "Put " << '"' << borrow[i].title << '"' << " after " << '"' << myVector[j].title << '"' << endl;
							break;
						}
					if (!flag)
					{
						cout << "Put " << '"' << borrow[i].title << '"' << " first" << endl;
					}
				}
			}
			borrow.clear();
			flag_global = false;
			cout << "END" << endl;
		}

	}

	system("pause");
	return 0;
}