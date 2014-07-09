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
int head[MAX_N], to[MAX_N << 1], next[MAX_N << 1];
int n, m, e, dp[MAX_N][2], val;
vector<int> ans;

void addEdge(int u, int v) {
	to[e] = v, next[e] = head[u], head[u] = e++;
}

void dfs(int u, int f) {
	dp[u][0] = 1, dp[u][1] = 0;
	for (int i = head[u]; ~i; i = next[i]) {
		int v = to[i];
		if (v == f) continue;
		dfs(v, u);
		dp[u][0] += dp[v][0];
		dp[u][1] = max(dp[u][1], dp[v][0]);
	}
}

void bfs(int u, int f) {
	if (val > dp[u][1]) {
		val = dp[u][1];
		ans.clear(), ans.push_back(u);
	} else if (val == dp[u][1]) {
		ans.push_back(u);
	}
	for (int i = head[u]; ~i; i = next[i]) {
		int v = to[i];
		if (v == f) continue;
		dp[v][1] = max(dp[v][1], dp[u][0] - dp[v][0]);
		dp[v][0] = dp[u][0];
		bfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	fill(head, head + n + 5, -1), e = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	val = 100000;
	dfs(1, -1), bfs(1, -1);
	printf("%d %d\n", val, (int)ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
	}
	return 0;
}
