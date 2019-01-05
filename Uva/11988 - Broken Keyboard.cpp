#include<iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	string line;
	while (cin >> line){
		list<char>LL;
		list<char>::iterator it = LL.begin();
		for (int i = 0; i < line.size(); i++){
		/*	if (line[i] == '[' || line[i] == ']'){
				string temp = "";
				int save_index = i;
				for (int j = i + 1; j < line.size(); j++){
					if (line[j] == '[' || line[j] == ']' ){ i = j - 1; break; }
					temp += line[j];
					if (j == line.size() - 1)
						i = j;
				}
				if (line[save_index] == '[')
					for (int k = temp.size() - 1; k >= 0; k--) LL.push_front(temp[k]);
				else 
					for (int k = 0; k < temp.size(); k++) LL.push_back(temp[k]);
			}
			else
				LL.push_back(line[i]);*/
			if (line[i] == '[') it = LL.begin();
			else if (line[i] == ']') it = LL.end();
			else LL.insert(it, line[i]);
		}
		it = LL.begin();
		for (; it != LL.end(); it++){
			cout << *it;
		}
		cout << endl;
	}
	system("pause");
}