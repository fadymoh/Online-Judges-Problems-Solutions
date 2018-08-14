#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		string word;
		cin >> word;
		vector<string> tokenizer;
		int found = 0;
		int group_length = word.length() / n;
		while (found < word.length()){
			string temp = word.substr(found, group_length);
			reverse(temp.begin(), temp.end());
			tokenizer.push_back(temp);
			found += group_length;
		}
		for (int i = 0; i < tokenizer.size(); ++i)
			cout << tokenizer[i];
		cout << endl;
	}
	system("pause");
	return 0;
}