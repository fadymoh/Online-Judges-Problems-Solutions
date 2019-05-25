#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// sieve of sundaram (naive implementation)
std::vector<long long > primes_upto(long long N)
{
	const long long  M = N / 2;
	std::vector<bool> sieve(M, true);
	for (int i = 1; i < M; ++i)
	{
		const int L = (M - i) / (2 * i + 1);
		for (int j = i; j <= L; ++j)
			sieve[i + j + 2 * i*j] = false;
	}
	std::vector<long long > primes;
	primes.push_back(2);
	for (int i = 1; i < M; ++i)
		if (sieve[i]) primes.push_back(i * 2 + 1);
	return primes;
}
long long smallest_prime_factor(long long N)
{
	if (N < 2) return N;

	std::vector<long long> primes = primes_upto(sqrt(N) + 1);
	for (std::vector<long long>::size_type i = 0; i < primes.size(); ++i)
		if ((N % primes[i]) == 0) return primes[i];

	return N;
}
int main()
{
	long long n;
	scanf("%lld", &n);
	long long d = smallest_prime_factor(n);
	printf("%lld", 1 + (n - d) / 2);
	return 0;
}
