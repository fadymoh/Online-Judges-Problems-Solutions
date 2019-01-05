#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;
int n, m;
struct domino{
	int left = -1, right = -1;
};
domino arr[100], given[100];
bool used[100], flag;
void backtrack(int x)
{

	if (x >= n){
		if (arr[n + 1].left == arr[n].right) {
			flag = true;
		}
		else return;
	}

	for (int i = 0; i < m; i++){
		if (!used[i]){
			
			if (arr[x].right == given[i].left){
				domino temp;
				used[i] = true;
				temp = arr[x + 1];
				arr[x + 1].left = arr[x].right;
				arr[x + 1].right = given[i].right;
				backtrack(x+1);
				arr[x + 1] = temp;
				used[i] = false;
			}
			if (arr[x].right == given[i].right){
				domino temp;
				used[i] = true;
				temp = arr[x + 1];
				arr[x + 1].left = arr[x].right;
				arr[x + 1].right = given[i].left;
				backtrack(x + 1);
				arr[x + 1] = temp;
				used[i] = false;
			}
			
		}
	}
}
int main()
{
	do {
		cin >> n >> m;
		flag = false;
		if (n == 0) break;
		for (int i = 0; i < 50; i++) used[i] = 0;
		cin >> arr[0].left >> arr[0].right >> arr[n + 1].left >> arr[n + 1].right;
		for (int i = 0; i < m; i++)
			cin >> given[i].left >> given[i].right;
		backtrack(0);
		flag ? printf("YES\n") : printf("NO\n");
	} while (true);


	system("pause");
	return 0;
}

