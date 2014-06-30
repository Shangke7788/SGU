#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	int ans = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans *= i - 1;
			n /= i;
			while (n % i == 0) {
				ans *= i;
				n /= i;
			}
		}
	}
	if (n != 1) {
		ans *= n - 1;
	}
	printf("%d\n", ans);
	return 0;
}
