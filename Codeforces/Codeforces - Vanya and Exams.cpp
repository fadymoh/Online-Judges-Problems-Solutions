#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n, r, avg, a,b, sum = 0;
	scanf("%lld %lld %lld", &n, &r, &avg);
	vector<pair<long long, long long>> myVector;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &a, &b);
		sum += a;
		myVector.push_back({ b,a }); // first is the number of essay, and second is the grade
	}
	sort(myVector.begin(), myVector.end());
	int idx = 0;
	unsigned long long int increased = 0;
	while (sum < avg * n)
	{
		long long tmp = min(avg*n - sum, r - myVector[idx].second);
		increased += tmp * myVector[idx].first;
		++idx;
		sum += tmp;
	}
	printf("%lld\n", increased);
	return 0;
}
