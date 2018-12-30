#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct rect {
	long x1, y1, x2, y2;
	long size;
};
int main()
{
	int n;
	cin >> n;
	vector<rect> arr;
	for (int i = 0; i < n; ++i)
	{
		rect temp;
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		temp.size = abs(temp.x2 - temp.x1) * abs(temp.y2 - temp.y1);
		arr.push_back(temp);
	}
	//sort(arr.begin(), arr.end());
	int i = 0;
	rect finall, prev;
	for (i = 0; i < n; ++i)
	{
		rect x = arr[i];
		int counter = 1;
		for (int j = 0; j < n; ++j)
		{
			rect y = arr[j];
			if (((y.x1 <= x.x2 && y.x1 >= x.x1) || (y.x2 <= x.x2 && y.x2 >= x.x1)) &&
				((y.y1 <= x.y2 && y.y1 >= x.y1) || (y.y2 <= x.y2 && y.y2 >= x.y1)))
			{
				counter = counter + 1;
				prev = x;
				rect inter;
				inter.x1 = max(x.x1, y.x1);
				inter.y1 = max(x.y1, y.y1);
				inter.x2 = min(x.x2, y.x2);
				inter.y2 = min(x.y2, y.y2);
				x = inter;
			}
		}
		if (counter >= n - 1)
		{
			finall = x;
			break;
		}
	}
	rect out;
	out.x1 = max(finall.x1, prev.x1);
	out.y1 = max(finall.y1, prev.y1);
	out.x2 = min(finall.x2, prev.x2);
	out.y2 = min(finall.y2, prev.y2);
	cout << out.x1 << ' ' << out.y1 << endl;
	return 0;
}