#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 110;
int a[MAX_N][MAX_N], n, m, k, src, des;
map< pair<int, int>, int > mp;
int res[MAX_N], rn;
int g[MAX_N], vis[MAX_N];

void dij(int s) {
	for (int i = 1; i <= n; i++) {
		g[i] = 1000000;
		vis[i] = 0;
	}
	g[s] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 1000000, k = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && tmp > g[j]) {
				tmp = g[j];
				k = j;
			}
		}
		if (k == -1) break;
		vis[k] = 1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				g[j] = min(g[j], g[k] + a[k][j]);
			}
		}
	}
}

struct Node {
	int v, f;
	bool is[MAX_N];
	Node() {}
	Node(int v, int f): v(v), f(f) {}
	Node(const Node& o) {
		v = o.v;
		f = o.f;
		for (int i = 1; i <= n; i++) {
			is[i] = o.is[i];
		}
	}
	bool operator < (const Node & o) const {
		return f + g[v] > o.f + g[o.v];
	}
};

priority_queue<Node> q;

int astar(int src, int des) {
	while (!q.empty()) q.pop();
	mp[make_pair(src, 0)] = -1;
	Node x = Node(src, 0);
	for (int i = 1; i <= n; i++) {
		x.is[i] = false;
	}
	x.is[src] = true;
	q.push(x);
	while (!q.empty()) {
		Node pre = q.top();
		q.pop();
		if (pre.v == des) {
			if (! --k) {
				return pre.f;
			} else {
				continue;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!pre.is[i] && a[pre.v][i] != -1) {
				x = Node(i, pre.f + a[pre.v][i]);
				for (int j = 1; j <= n; j++) {
					x.is[j] = pre.is[j];
				}
				x.is[i] = true;
				q.push(x);
				if (mp.find(make_pair(x.v, x.f)) == mp.end()) {
					mp[make_pair(x.v, x.f)] = pre.v;
				} else {
					mp[make_pair(x.v, x.f)] = min(mp[make_pair(x.v, x.f)], pre.v);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = -1;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		a[u][v] = a[v][u] = c;
	}
	scanf("%d%d", &src, &des);
	dij(src);
	int ans = astar(des, src);
	int x = src, y = ans;
	rn = 0, res[rn++] = x;
	while (mp[make_pair(x, y)] != -1) {
		int z = mp[make_pair(x, y)];
		y -= a[x][z];
		x = z;
		res[rn++] = x;
	}
	printf("%d %d\n", ans, rn);
	for (int i = 0; i < rn; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}
