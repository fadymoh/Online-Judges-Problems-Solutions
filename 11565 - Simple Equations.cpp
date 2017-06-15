#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int n,a,b,c;
	cin >> n;
	while (n--){
		cin >> a >> b >> c;
		int counter = 0;
		for (int x = -100; x <= 100; x++)
			for (int y = -100; y <= 100; y++)
				for (int z = -100; z <= 100; z++)
					if (x != y && y != z && x != z && (x + y + z) == a && (x*y*z) == b && (x*x + y*y + z*z) == c)
					{
						if (!counter)	cout << x << " " << y << " " << z << endl;
						counter++;
					}
		if (!counter) cout << "No solution." << endl;
	}
	


	system("pause");
	return 0;
}