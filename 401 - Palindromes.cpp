#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
bool ispalindrome(string x)
{
	string temp = x;
	reverse(temp.begin(), temp.end());
	return (x == temp);
}
bool ismirrored(string x)
{
	string temp = x;
	int i;
	rep(i, 0, x.size()-1)
		switch (x[i]){
		case 'E': temp[i] = '3'; break;
		case '3': temp[i] = 'E'; break;
		case 'J': temp[i] = 'L'; break;
		case 'L': temp[i] = 'J'; break;
		case 'S': temp[i] = '2'; break;
		case '2': temp[i] = 'S'; break;
		case 'Z': temp[i] = '5'; break;
		case '5': temp[i] = 'Z'; break;
		case 'A':
		case 'H':
		case 'I':
		case 'M':
		case 'O':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case '1':
		case '8': 
			break;
		default: return false;
	}
	reverse(temp.begin(), temp.end());
	return (x == temp);
}
int main()
{
	string temp;
	while (cin >> temp){
		bool palindrome = ispalindrome(temp), mirrored = ismirrored(temp);
		cout << temp << " -- ";
		if (palindrome)
			if (mirrored) cout << "is a mirrored palindrome.";
			else cout << "is a regular palindrome.";
		else
		if (mirrored) cout << "is a mirrored string.";
		else cout << "is not a palindrome.";
		cout << endl << endl;
	}
	system("pause");
	return 0;
}


