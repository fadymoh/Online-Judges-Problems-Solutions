#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct block
{
	int x, y, z;
	bool operator < (const block &b)
	{
		if (x == b.x)
		{
			return y < b.y;
		}
		else return x < b.x;
	}
};
vector <block> arr;
vector <int> length;
int main() {
	int n, case_counter = 0;
	while (cin >> n, n != 0) {
		for (int i = 0; i < n; ++i)
		{
			int in[3];
			cin >> in[0] >> in[1] >> in[2];
			sort(in, in + 3);
			do {
				block temp;
				temp.x = in[0];
				temp.y = in[1];
				temp.z = in[2];
				arr.push_back(temp);
			} while (next_permutation(in, in + 3));
		}
		int maxx = -1;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); ++i)
		{
			int max_height = 0;
			for (int j = i-1; j >= 0; --j)
				if (arr[j].x < arr[i].x && arr[j].y < arr[i].y && arr[j].z > max_height)
					max_height = arr[j].z;
			arr[i].z+= max_height;
			maxx = max(maxx, arr[i].z);
		}
		cout << "Case " << ++case_counter << ": maximum height = " << maxx << endl;
		arr.clear();
	}
	return 0;
}