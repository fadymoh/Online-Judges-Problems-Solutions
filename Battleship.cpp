#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;
char arr[101][101];
int n, k;

bool comparatorr(int i, int j)
{
	return i > j;
}
bool sortbysec(const pair<string, int> &a,
	const pair<string, int> &b)
{
	return (a.first < b.first);
}
struct directions {
	int up = 1, down = 1, left = 1, right = 1;
};
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); ++i)
directions calculate_directions(int i, int j)
{
	directions temp;
	for (int x = j + 1; x <= j + k && x < n; ++x)
		if (arr[i][x] != '.') break;
		else temp.right++;
		if (temp.right > k) temp.right = k;
	for (int x = j - 1; x >= j - k && x >= 0; x--)
		if (arr[i][x] != '.') break;
		else temp.left++;
		if (temp.left > k) temp.left = k;
	for (int x = i + 1; x <= i + k && x < n; ++x)
		if (arr[x][j] != '.') break;
		else temp.down++;
		if (temp.down > k) temp.down = k;
	for (int x = i - 1; x >= i - k && x  >= 0; x--)
		if (arr[x][j] != '.') break;
		else temp.up++;
		if (temp.up > k) temp.up = k;
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}
	directions mygrid[101][101];
	int max = -1;
	int x, y;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (arr[i][j] == '.') {
				mygrid[i][j] = calculate_directions(i, j);
				int temp_x = mygrid[i][j].right + mygrid[i][j].left - k + 1;
				int temp_y = mygrid[i][j].down + mygrid[i][j].up - k + 1;
				if (temp_x < 0) temp_x = 0;
				if (temp_y < 0) temp_y = 0;
				if (temp_x + temp_y > max){
					max = temp_x + temp_y;
					x = i;
					y = j;
				}
			}
		}
	}
	cout << x + 1<< " " << y + 1<< endl;
	system("pause");
	return 0;
}
// xxxxxxx