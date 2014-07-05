#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int a[4][4], b[4][4], n;
bool ok;
int fx[4][2] = {
	{0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

inline int ch(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int now) {
	if (ok) return;
	if (now == n * n) {
		for (int i = 0; i < n; i++) {
			int tp = 0;
			for (int j = 0; j < 4; j++) {
				tp += ch(n - 1 + fx[j][0], i + fx[j][1]) && 
					a[n - 1 + fx[j][0]][i + fx[j][1]] > a[n - 1][i];
			}
			if (tp != b[n - 1][i]) {
				return;
			}
		}
		ok = true;
		return;
	}
	for (int d = 1; d <= 9; d++) {
		a[now / n][now % n] = d;
		if (now >= n) {
			int tp = 0;
			for (int j = 0; j < 4; j++) {
				tp += ch(now / n - 1 + fx[j][0], now % n + fx[j][1]) &&
					a[now / n - 1 + fx[j][0]][now % n + fx[j][1]] > a[now / n - 1][now % n];
			}
			if (tp != b[now / n - 1][now % n]) {
				continue;
			}
		}
		dfs(now + 1);
		if (ok) return;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	ok = false, dfs(0);
	if (ok) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d%c", a[i][j], " \n"[j == n - 1]);
			}
		}
	} else {
		printf("NO SOLUTION\n");
	}
	return 0;
}
