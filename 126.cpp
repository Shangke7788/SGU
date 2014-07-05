#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	int d = __gcd(a, b);
	a /= d, b /= d;
	int ans = -1;
	for (int i = 0; i < 31; i++) {
		if (a + b == (1 << i)) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
