#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unordered_map>
using namespace std;

unordered_map <int, int> freq;
int freq_char[26];

int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		memset(freq_char, 0, sizeof freq_char);
		for (char c : s)
			++freq_char[c - 'a'];
		int mask = 0;
		for (int j = 0; j < 26; ++j)
		{
			if (freq_char[j] % 2)
				mask = mask | (1 << j);
		}
		res += freq[mask];
		for (int j = 0; j < 26; ++j)
		{
			int mask2 = mask;
			mask2 ^= (1 << j);
			res += freq[mask2];
		}
		++freq[mask];
	}
	cout << res << endl;
	return 0;
}