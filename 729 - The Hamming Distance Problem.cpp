#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, h;
vector<int> sol;
vector <string> out;
bool equals(int x)
{
	int sum = 0;
	while (x != 0)
	{
		int temp = x % 2;
		x /= 2;
		sum += temp;
	}
	return sum == h;
}
void backtrack(int idx)
{
	if (equals(idx))
	{
		sol.push_back(idx);
	}
	if (idx < pow(2, n) - 1)
		backtrack(idx + 1);
}
	bool temp (const int& first,const int& second)
	{
		return first > second;
	}

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		cin >> n >> h;
		backtrack(1);
		for (int i = 0; i < sol.size(); ++i)
		{
			int x = 0;
			string app = "";
			while (x != n)
			{
				app.append(((sol[i] % 2) ? "1" : "0"));
				sol[i] /= 2;
				++x;
			}
			reverse(app.begin(), app.end());
			out.push_back(app);
		}
		sort(out.begin(), out.end());
		for (int i = 0; i < out.size(); ++i)
			cout << out[i] << endl;
		sol.clear();
		out.clear();
		cin.ignore();
		if (tc) cout << endl;
	}
	return 0;
}