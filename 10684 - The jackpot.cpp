#include <iostream>
#include <algorithm>
using namespace std;
int n, temp;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n, n != 0)
	{
		int ans = -1, sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			sum += temp;
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (ans > 0) cout << "The maximum winning streak is " << ans << ".\n";
		else cout << "Losing streak.\n";
	}
	system("pause");
	return 0;
}