#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, F = 0, S = 0;
	string in;
	cin >> n >> in;
	char prev;
	prev = in[0];
	for (int i = 1; i < n; ++i)
	{
		if (prev != in[i])
		{
			if (prev == 'F') ++F;
			else ++S;
		}
		prev = in[i];
	}
	if (S > F) cout << "YES";
	else cout << "NO";
	return 0;
}