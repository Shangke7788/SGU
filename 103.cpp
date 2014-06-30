#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_M = 14033 * 2;
const int MAX_N = 333;
const int INF = 1000000000;

int head[MAX_N], to[MAX_M], next[MAX_M], cost[MAX_M], n, m, e;
int src, des, dis[MAX_N], last[MAX_N];
char s[3];
struct Node {
	int type;
	int ci, b, p;
} p[MAX_N];

void addEdge(int u, int v, int c) {
	to[e] = v, cost[e] = c;
	next[e] = head[u], head[u] = e++;
}

pair<int, int> get_type(int u, int t) {
	if (p[u].ci > t) {
		return make_pair(p[u].type, p[u].ci - t);
	} else {
		t -= p[u].ci;
		t %= p[u].b + p[u].p;
		if (p[u].type == 1) {
			if (p[u].p > t) {
				return make_pair(0, p[u].p - t);
			} else {
				return make_pair(1, p[u].b + p[u].p - t);
			}
		} else {
			if (p[u].b > t) {
				return make_pair(1, p[u].b - t);
			} else {
				return make_pair(0, p[u].p + p[u].b - t);
			}
		}
	}
}

int get_next(int u, int v, int t) {
	pair<int, int> tu = get_type(u, t);
	pair<int, int> tv = get_type(v, t);
	if (tu.first == tv.first) {
		return 0;
	} else if (tu.second != tv.second) {
		return min(tu.second, tv.second);
	} else if (tu.first == 0) {
		if (tu.second + p[u].b != tv.second + p[v].p) {
			return min(tu.second + p[u].b, tv.second + p[v].p);
		} else {
			return min(tu.second + p[u].b + p[u].p, tv.second + p[v].p + p[v].b);
		}
	} else {
		if (tu.second + p[u].p != tv.second + p[v].b) {
			return min(tu.second + p[u].p, tv.second + p[v].b);
		} else {
			return min(tu.second + p[u].p + p[u].b, tv.second + p[v].p + p[v].b);
		}
	}
}

void dij() {
	dis[src] = 0;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	while (!q.empty()) q.pop();
	q.push(make_pair(0, src));
	while (!q.empty()) {
		pair<int, int> pre = q.top();
		q.pop();
		if (pre.first != dis[pre.second]) {
			continue;
		}
		if (pre.second == des) {
			return;
		}
		for (int i = head[pre.second]; ~i; i = next[i]) {
			int v = to[i];
			int c = cost[i] + get_next(pre.second, v, pre.first);
			if (dis[v] > dis[pre.second] + c) {
				dis[v] = dis[pre.second] + c;
				last[v] = pre.second;
				q.push(make_pair(dis[v], v));
			}
		}
	}
}

void print(int x) {
	if (~last[x]) {
		print(last[x]);
	}
	printf("%d%c", x, " \n"[x == des]);
}

int main() {
	scanf("%d%d", &src, &des);
	scanf("%d%d", &n, &m);
	fill(head, head + n + 5, -1), e = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d%d", s, &p[i].ci, &p[i].b, &p[i].p);
		p[i].type = s[0] == 'B';
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		if (p[u].type != p[v].type && p[u].ci == p[v].ci && p[u].b == p[v].p && p[u].p == p[v].b) continue;
		addEdge(u, v, c), addEdge(v, u, c);
	}
	fill(dis, dis + n + 5, INF), last[src] = -1;
	dij();
	if (dis[des] == INF) {
		printf("0\n");
	} else {
		printf("%d\n", dis[des]);
		print(des);
	}
	return 0;
}
