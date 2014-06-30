#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 111;
const int INF = 1000000000;
int dp[MAX_N][MAX_N], n, m;
int last[MAX_N][MAX_N], a[MAX_N][MAX_N];

void print(int x, int y) {
	if (!x) {
		return;
	}
	print(x - 1, last[x][y]);
	printf("%d%c", y, " \n"[x == n]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	fill(dp[0], dp[n + 1], -INF);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= i + m - n; j++) {
			for (int k = i - 1; k < j; k++) {
				if (dp[i][j] < dp[i - 1][k] + a[i][j]) {
					dp[i][j] = dp[i - 1][k] + a[i][j];
					last[i][j] = k;
				}
			}
		}
	}
	int ans = -INF, po = -1;
	for (int i = n; i <= m; i++) {
		if (ans < dp[n][i]) {
			ans = dp[n][i];
			po = i;
		}
	}
	printf("%d\n", ans);
	print(n, po);
	return 0;
}
