#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 16666;
int n, a[MAX_N], ans;
int head[MAX_N], next[MAX_N << 1], to[MAX_N << 1], e;

void addEdge(int u, int v) {
	to[e] = v, next[e] = head[u], head[u] = e++;
}

int dfs(int u, int f) {
	int res = a[u];
	for (int i = head[u]; ~i; i = next[i]) {
		int v = to[i];
		if (v == f) continue;
		res += dfs(v, u);
	}
	ans = max(ans, res);
	return max(res, 0);
}

int main() {
	scanf("%d", &n), fill(head, head + n + 2, -1), e = 0;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	ans = -10000, dfs(1, -1);
	printf("%d\n", ans);
	return 0;
}
