#include <iostream>
#include <string>
using namespace std;

int main()
{
	string in;
	string line;
	cin >> in;
	getline(cin, line);
	int found = line.find(in[1]);
	if (found == string::npos)
		cout << "NO\n";
	else cout << "YES\n";
	return 0;
}