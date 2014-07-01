#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 111;
int a[MAX_N][MAX_N];
vector<int> ans;

int main() {
	int n;
	scanf("%d", &n);
	int sum = n * n, step = n / 2 * 2 + 1, now = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = now++;
		}
	}
	now = 2;
	while (sum != 4 && sum != 1) {
		printf("%d", step);
		ans.clear();
		int pp = now / 2;
		for (int j = pp; j <= n - pp + 1; j++) {
			if ((now - j - pp + 1) & 1) {
				if (a[pp][j]) {
					ans.push_back(a[pp][j]);
					a[pp][j] = 0;
				}
			}
			if ((n - 1 + now - j - pp + 1) & 1) {
				if (a[n - pp + 1][j]) {
					ans.push_back(a[n - pp + 1][j]);
					a[n - pp + 1][j] = 0;
				}
			}
		}
		for (int i = pp; i <= n - pp + 1; i++) {
			if ((now - i - pp + 1) & 1) {
				if (a[i][pp]) {
					ans.push_back(a[i][pp]);
					a[i][pp] = 0;
				}
			}
			if ((n - 1 + now - i - pp + 1) & 1) {
				if (a[i][n - pp + 1]) {
					ans.push_back(a[i][n - pp + 1]);
					a[i][n - pp + 1] = 0;
				}
			}
		}
		int t = ans.size();
		sum -= t;
		for (int i = 0; i < t; i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
		step += 2, now++;
	}
	if (sum == 4) {
		printf("%d %d\n", step, a[n / 2][n / 2]);
		step += 2;
		printf("%d %d %d\n", step, a[n / 2][n / 2 + 1], a[n / 2 + 1][n / 2]);
	}
	return 0;
}
