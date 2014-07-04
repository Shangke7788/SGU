#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

bool isprime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x = 0;
		scanf("%d", &x);
		if (x == 1 || isprime(x)) {
			printf("No%c", "\n\n"[i == n]);
		} else {
			for (int j = 2; j * j <= x; j++) {
				if (x % j == 0) {
					x /= j;
					break;
				}
			}
			if (isprime(x)) {
				printf("Yes%c", "\n\n"[i == n]);
			} else {
				printf("No%c", "\n\n"[i == n]);
			}
		}
	}
	return 0;
}
