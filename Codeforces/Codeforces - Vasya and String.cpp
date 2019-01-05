#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string in;
	cin >> in;
	int j = 0;
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		while (j < n && count < k)
		{
			if (in[i] != in[j++]) ++count;
		}
		mx = max(mx, j - i);
	}
	return 0;
}