#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	int start, end;
	for (int i = 0; i < q; ++i)
	{
		cin >> start >> end;
		--start;
		string temp = s.substr(start, abs(end - start));
		int found = start - t.length(), itr = start, counter = 0;
		while (true)
		{
			found = s.find(t, found +t.length());
			if (found > end || found == -1)
				break;
			if (found + t.length() <= end)
			++counter;
		}
		cout << counter << endl;
	}
	return 0;
}