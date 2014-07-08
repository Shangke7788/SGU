#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int INF = 10000;
char s[77][10];
int dp[2][1 << 7 + 7];
int m, n, ans;

void dfs(int i, int y, int p, int x, int val) {
	if (p == n) {
		dp[i & 1][y] = min(dp[i & 1][y], val);
		return;
	}
	int no = (x >> 2 * (n - 1 - p)) & 3;
	if (s[i][p] == '*') {
		if (no == 1) {
		} else {
			dfs(i, (y << 2) | 3, p + 1, x, val);
		}
		return;
	}
	if (no == 1) {
		dfs(i, y << 2, p + 1, x, val);
	} else if (no == 2) {
		dfs(i, (y << 2) | 1, p + 1, x, val + 1);
		if (p != n - 1 && s[i][p + 1] == '.' && ((x >> 2 * (n - p - 2)) & 3) != 1) {
			dfs(i, y << 4, p + 2, x, val + 1);
		}
	} else {
		dfs(i, (y << 2) | 1, p + 1, x, val + 1);
		if ((y & 3) != 2) {
			dfs(i, (y << 2) | 2, p + 1, x, val);
		}
		if (p != n - 1 && s[i][p + 1] == '.' && ((x >> 2 * (n - p - 2)) & 3) != 1) {
			dfs(i, y << 4, p + 2, x, val + 1);
		}
	}
}

void gao(int i, int x, int p) {
	if (p == n) {
		if (dp[i + 1 & 1][x] >= INF) {
			return;
		}
		dfs(i, 0, 0, x, dp[i + 1 & 1][x]);
		return;
	}
	if (s[i - 1][p] == '*') {
		gao(i, (x << 2) | 3, p + 1);
		return;
	}
	gao(i, (x << 2) | 0, p + 1);
	gao(i, (x << 2) | 1, p + 1);
	if ((x & 3) != 2) {
		gao(i, (x << 2) | 2, p + 1);
	}
}

void calc(int pre, int x, int p) {
	if (p == n) {
		ans = min(ans, dp[pre][x]);
		return;
	}
	if (s[m][p] == '*') {
		calc(pre, (x << 2) | 3, p + 1);
	}
	calc(pre, x << 2, p + 1);
	calc(pre, (x << 2) | 2, p + 1);
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%s", s[i]);
	}
	fill(dp[0], dp[2], INF);
	int now = 0;
	for (int i = 0; i < n; i++) {
		s[0][i] = '*';
		now = (now << 2) | 3;
	}
	dp[0][now] = 0;
	int pre = 0, cur = 1;
	for (int i = 1; i <= m; i++) {
		fill(dp[cur], dp[cur + 1], INF);
		gao(i, 0, 0);
		swap(pre, cur);
	}
	ans = INF, calc(pre, 0, 0);
	printf("%d\n", ans);
	return 0;
}
