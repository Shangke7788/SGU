#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

char sp[101010];
int n, vis[1010];
bool a[1010][1010];

int ans[2020], s, e;
const int MID = 1005;

void dfs(bool ok) {
	if (ok) {
		for (int i = 1; i <= n; i++) {
			if (a[ans[e - 1]][i] && !vis[i]) {
				vis[i]++;
				ans[e++] = i;
				dfs(ok);
				return;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[ans[s]][i] && !vis[i]) {
				vis[i]++;
				ans[--s] = i;
				dfs(ok);
				return;
			}
		}
	}
}

void insert(int x) {
	for (int i = s; i < e - 1; i++) {
		if (a[x][ans[i]] && a[x][ans[i + 1]]) {
			for (int j = s - 1; j < i; j++) {
				ans[j] = ans[j + 1];
			}
			ans[i] = x;
			s--;
			vis[x]++;
			break;
		}
	}
}

void gao() {
	for (int i = s; i < e - 1; i++) {
		if (a[ans[s]][ans[i + 1]] && a[ans[e - 1]][ans[i]]) {
			if (i >= MID) {
				reverse(ans + i + 1, ans + e);
			} else {
				reverse(ans + s, ans + i + 1);
			}
			return;
		}
	}
	assert(false);
}

int main() {
	scanf("%d", &n);
	gets(sp);
	for (int i = 1; i <= n; i++) {
		gets(sp);
		int now = 0, spn = 0;
		while (sp[spn]) {
			if (sp[spn] == ' ') {
				a[i][now] = true;
				now = 0;
			} else {
				now = now * 10 + sp[spn] - '0';
			}
			spn++;
		}
		a[i][now] = true;
	}
	s = MID, e = MID;
	ans[e++] = 1, vis[1]++;
	dfs(true), dfs(false);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			insert(i);
		}
	}
	assert(e - s == n);
	gao();
	for (int i = s; i < e; i++) {
		assert(ans[i] >= 1 && ans[i] <= n);
	}
	ans[e] = ans[s];
	for (int i = s; i < e; i++) {
		assert(a[ans[i]][ans[i + 1]]);
	}
	for (int i = 1; i <= n; i++) {
		assert(vis[i] == 1);
	}
	int now = MID;
	do {
		printf("%d ", ans[now]);
		now++;
		if (now == e) now = s;
	} while (now != MID);
	puts("1\n");
	return 0;
}
