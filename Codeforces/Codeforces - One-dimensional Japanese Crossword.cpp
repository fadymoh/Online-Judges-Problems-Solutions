#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string in;
	cin >> in;
	int arr[101];
	bool consec = false;
	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!consec)
		{
			if (in[i] == 'B')
			{
				consec = true;
				++arr[counter];
			}
		}
		else
		{
			if (in[i] == 'B') ++arr[counter];
			else {
				consec = false;
				++counter;
			}
		}
	}
	for (int i = 0; i < counter; ++i)
		cout << arr[i] << ' ';
	return 0;
}