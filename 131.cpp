#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 9;
int a[1 << MAX_N][1 << MAX_N], n, m;
lint b[10][1 << MAX_N];

void dfs(int x, int y, int now, bool l = false) {
	if (now == n) {
		a[x][y]++;
		return;
	}
	if (l) {
		if (x & (1 << now)) {
			dfs(x, y, now + 1);
		} else {
			if (now != n - 1) {
				if (x & (1 << now + 1)) {
				} else {
					dfs(x, y | (1 << now + 1), now + 2);
					dfs(x, y, now + 2);
				}
			}
		}
	} else if (x & (1 << now)) {
		dfs(x, y, now + 1);
	} else {
		dfs(x, y | (1 << now), now + 1);
		if (now != 0 && !(y & (1 << now - 1))) {
			y ^= 1 << now - 1;
			dfs(x, y | (1 << now), now + 1);
			y ^= 1 << now - 1;
		}
		if (now != n - 1) {
			y ^= 1 << now + 1;
			dfs(x, y ^ (1 << now), now + 1, true);
			y ^= 1 << now + 1;
			if (x & (1 << now + 1)) {
			} else {
				dfs(x, y | (1 << now), now + 2);
				dfs(x, y | (1 << now + 1), now + 2);
				dfs(x, y, now + 2);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if (n > m) {
		swap(n, m);
	}
	int N = 1 << n;
	for (int i = 0; i < N; i++) {
		dfs(i, 0, 0);
	}
	b[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				b[i][k] += b[i - 1][j] * a[j][k];
			}
		}
	}
	printf("%I64d\n", b[m][0]);
	return 0;
}
