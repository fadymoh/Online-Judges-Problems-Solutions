#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
vector<int> l;
vector<int> p;
vector<int> id;
void print(int i)
{
	if (i != -1)
		print(p[i]), printf("%d\n", a[i]);
}
int main()
{
	int temp;
	while (cin >> temp, !cin.eof()) a.push_back(temp);
	int lis = 0, lis_end, size = a.size();
	l.resize(size);
	p.resize(size);
	id.resize(size);

	for (int i = 0; i < a.size(); ++i)
	{
		int x = a[i];

		int ind = lower_bound(l.begin(), l.begin() + lis, x) - l.begin();

		l[ind] = x;
	
		id[ind] = i;

		p[i] = ind ? id[ind - 1] : -1;

		if (ind + 1 >= lis)
			lis = ind + 1, lis_end = i;
	}
	cout << lis << "\n-\n";
	print(lis_end);
	system("pause");
	return 0;
}