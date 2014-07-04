#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 111;
int g[MAX_N][MAX_N], n, a[MAX_N][MAX_N];
int d[MAX_N], vis[MAX_N];

void dfs(int x, int c) {
	vis[x] = 1;
	int now = 0;
	while (g[x][now]) {
		if (a[x][g[x][now]]) {
			now++;
			continue;
		}
		a[x][g[x][now]] = a[g[x][now]][x] = 1 << c;
		dfs(g[x][now++], c = !c);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int last = -1, now = 0;
		while (last) {
			scanf("%d", &last);
			g[i][now++] = last;
			if (last) {
				d[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if ((d[i] & 1) && !vis[i]) {
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] <= 1) continue;
		int now = 0, f = 0;
		while (g[i][now] && f != 3) {
			f |= a[i][g[i][now++]];
		}
		if (f != 3) {
			printf("No solution\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int now = 0;
		while (g[i][now]) {
			printf("%d ", a[i][g[i][now++]]);
		}
		printf("0\n");
	}
	return 0;
}
