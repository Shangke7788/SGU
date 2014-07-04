#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10101;
int n, a[MAX_N];

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				n = i;
				break;
			}
		}
		if (n == 0) {
			printf("0\n");
			continue;
		}
		int ans = 0, now = 1;
		for (int i = 0; i < n; i++) {
			now = a[i] % 9 * now % 9;
			ans += now;
		}
		ans %= 9;
		if (ans == 0) ans = 9;
		printf("%d\n", ans);
	}
	return 0;
}
