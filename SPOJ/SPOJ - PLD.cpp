#include <bits/stdc++.h>
#include <ext/numeric> 
using namespace std;
using namespace __gnu_cxx;
const int MOD = 1e9 + 7, N = 3e4 + 3;
struct MUL {
	int operator ()(int a, int b) const {
		return (1LL * a * b) % MOD;
	}
};
int identity_element(const MUL &) {
	return 1;
}
const MUL mul;
const int base = 128, inverse = power(base, MOD - 2, mul);
struct ADD {
	int operator ()(int a, int b) const {
		return (0LL + a + b + MOD) % MOD;
	}
};
const ADD add;

int k;
char str[N];
int main() {
	int h1 = 0, h2 = 0, p = 1;
	scanf("%d %s", &k, str);
	for (int i = 0, j = k - 1; i < k; ++i, j--) {
		h1 = mul(h1, base);
		h1 = add(h1, str[i]);
		h2 = mul(h2, base);
		h2 = add(h2, str[j]);
		if (i)
			p = mul(p, base);
	}
	int res = 0;
	for (int i = 0, j = k; str[j - 1]; ++i, ++j) {
		res += h1 == h2;
		h1 = add(h1, -mul(str[i], p));
		h1 = mul(h1, base);
		h1 = add(h1, str[j]);

		h2 = add(h2, -str[i]);
		h2 = mul(h2, inverse);
		h2 = add(h2, mul(str[j], p));
	}
	cout << res << endl;
	return 0;
}