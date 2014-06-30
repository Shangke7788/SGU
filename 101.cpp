#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 111;

int head[7], to[MAX_N << 1], next[MAX_N << 1], e, n, d[7], fa[7];
vector<int> ans;
bool vis[MAX_N << 1];

void addEdge(int u, int v) {
	to[e] = v, next[e] = head[u], head[u] = e++;
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void dfs(int x) {
	for (int i = head[x]; ~i; i = next[i]) {
		if (vis[i]) continue;
		vis[i] = true, vis[i ^ 1] = true;
		dfs(to[i]);
		ans.push_back(i);
	}
}

int main() {
	scanf("%d", &n);
	memset(head, -1, sizeof(head)), e = 0;
	for (int i = 0; i < 7; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
		d[u]++, d[v]++;
		int x = find(u), y = find(v);
		if (x == y) continue;
		fa[x] = y;
	}
	int num = 0, ff = 0;
	for (int i = 0; i < 7; i++) {
		if (d[i] & 1) {
			num++;
		}
		if (d[i]) {
			ff |= 1 << find(i);
		}
	}
	if (ff != 1 && ff != 2 && ff != 4 && ff != 8 && ff != 16 && ff != 32 && ff != 64) {
		printf("No solution\n");
	} else if (num != 0 && num != 2) {
		printf("No solution\n");
	} else if (num == 0) {
		for (int i = 0; i < 7; i++) {
			if (d[i]) {
				dfs(i);
				break;
			}
		}
	} else {
		for (int i = 0; i < 7; i++) {
			if (d[i] & 1) {
				dfs(i);
				break;
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d %s\n", 1 + (ans[i] >> 1), ans[i] & 1 ? "-" : "+");
	}
	return 0;
}
