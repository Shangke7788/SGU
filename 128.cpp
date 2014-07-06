#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10101;
const int MID = MAX_N;
pair<int, int> p[MAX_N];
map<int, int> x[MAX_N << 1], y[MAX_N << 1];
map< pair<int, int>, int > a;
struct Node {
	int x1, x2, y;
	bool operator < (const Node& o) const {
		return x2 < o.x2;
	}
} q[MAX_N];
int head[MAX_N], to[MAX_N << 1], next[MAX_N << 1], n, e, vis[MAX_N];

void addEdge(int u, int v) {
	to[e] = v, next[e] = head[u], head[u] = e++;
}

void dfs(int x) {
	vis[x] = 1;
	for (int j = head[x]; ~j; j = next[j]) {
		int v = to[j];
		if (!vis[v]) {
			dfs(v);
		}
	}
}

struct Segment {
	int l, r, m;
} s[MAX_N << 3];

void build(int l, int r, int v) {
	s[v].l = l, s[v].r = r, s[v].m = 0;
	if (s[v].l == s[v].r) {
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, v << 1), build(mid + 1, r, v << 1|1);
}

void update(int l, int r, int v, int c) {
	if (s[v].l == l && s[v].r == r) {
		s[v].m = c;
		return;
	}
	int mid = s[v].l + s[v].r >> 1;
	if (mid >= r) {
		update(l, r, v << 1, c);
	} else if (l > mid) {
		update(l, r, v << 1|1, c);
	} else {
		update(l, mid, v << 1, c);
		update(mid + 1, r, v << 1|1, c);
	}
}

int find(int x, int v) {
	if (s[v].l == s[v].r) {
		return s[v].m;
	}
	s[v << 1].m = max(s[v << 1].m, s[v].m);
	s[v << 1|1].m = max(s[v << 1|1].m, s[v].m);
	int mid = s[v].l + s[v].r >> 1;
	if (mid >= x) {
		return find(x, v << 1);
	} else {
		return find(x, v << 1|1);
	}
}

int main() {
	scanf("%d", &n);
	int po = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
		if (++x[p[i].first += MID][p[i].second += MID] > 1) po = 1;
		if (++y[p[i].second][p[i].first] > 1) po = 1;
		a[p[i]] = i;
	}
	for (int i = 0; i < MAX_N + MID; i++) {
		int tmp = 0;
		for (map<int, int>::iterator it = x[i].begin(); it != x[i].end(); ++it) {
			tmp += it->second;
		}
		po |= tmp & 1;
		for (map<int, int>::iterator it = y[i].begin(); it != y[i].end(); ++it) {
			tmp += it->second;
		}
		po |= tmp & 1;
	}
	if (po) {
		printf("0\n");
	} else {
		fill(head, head + n + 1, -1), e = 0;
		for (int i = 0; i < MAX_N + MID; i++) {
			for (map<int, int>::iterator it = x[i].begin(); it != x[i].end(); ++it) {
				map<int, int>::iterator it2 = it;
				++it;
				ans += it->first - it2->first;
				addEdge(a[make_pair(i, it->first)], a[make_pair(i, it2->first)]);
				addEdge(a[make_pair(i, it2->first)], a[make_pair(i, it->first)]);
			}
			for (map<int, int>::iterator it = y[i].begin(); it != y[i].end(); ++it) {
				map<int, int>::iterator it2 = it;
				++it;
				ans += it->first - it2->first;
				addEdge(a[make_pair(it->first, i)], a[make_pair(it2->first, i)]);
				addEdge(a[make_pair(it2->first, i)], a[make_pair(it->first, i)]);
			}
		}
		dfs(1);
		for (int i = 1; i <= n; i++) po |= !vis[i];
		if (po) {
			printf("0\n");
		} else {
			int num = 0;
			for (int i = 0; i < MAX_N + MID; i++) {
				for (map<int, int>::iterator it = y[i].begin(); it != y[i].end(); ++it) {
					map<int, int>::iterator it2 = it;
					++it;
					q[num].x1 = it2->first, q[num].x2 = it->first, q[num].y = i;
					++num;
				}
			}
			sort(q, q + num), build(1, MAX_N + 10001, 1);
			int j = 0;
			for (int i = 0; i < MAX_N + MID; i++) {
				while (j < num && q[j].x2 == i) {
					int val = find(q[j].y, 1);
					if (val > q[j].x1) {
						printf("0\n");
						return 0;
					}
					j++;
				}
				for (map<int, int>::iterator it = x[i].begin(); it != x[i].end(); ++it) {
					map<int, int>::iterator it2 = it;
					++it;
					update(it2->first, it->first, 1, i);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
