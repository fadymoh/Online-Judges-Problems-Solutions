#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
long gcd(long a, long b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;

	if (a < b)
		return gcd(a, b % a);
	else
		return gcd(b, a % b);
}
int getlength(int num)
{
	int count = 0;
	while (num){
		num /= 10;
		++count;
	}
	return count;
}
void PrintNum(int num, bool isNeg, int preceedLength, int longest)
{
	if (isNeg)
		cout << "  ";
	cout << string(preceedLength, ' ') << setw(longest) << num << '\n';
}
int main()
{
	int n, i, x, T = 1;
	while (cin >> n, n){
		long sum = 0;
		rep(i, 1, n){
			cin >> x;
			sum += x;
		}
		cout << "Case " << T++ << ":\n";
		if (sum % n == 0){
			if (sum < 0)
				cout << "- ";
			cout << abs(sum / n) << '\n';
		}
		else{
			bool neg = (sum < 0);
			sum = abs(sum);
			double average = (float)sum / n, integral, frac;
			frac = modf(average, &integral);
			int integral_length = getlength(integral);
			sum = sum % n;
			int GCD = gcd(sum, n);
			int num = sum / GCD, denom = n / GCD;
			int maxx = max(getlength(num), getlength(denom));
			PrintNum(num, neg, integral_length, maxx);
			if (neg)
				cout << "- ";
			if (integral)
				cout << integral;
			cout << string(maxx, '-') << '\n';
			PrintNum(denom, neg, integral_length, maxx);
		}

	}

	system("pause");
	return 0;
}
