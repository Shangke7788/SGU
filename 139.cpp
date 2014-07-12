#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
enum {U = 0, D, L, R};
char w[2][5] = {"UDLR", "LRUD"};
// char w[2][5] = {"DSRL", "RLDS"};
int fx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int pw = 0, height, width, n, m;
vector<char> ans;
map<int, pair<int, int> > mp;
int a[MAX_N][MAX_N], sol[MAX_N][MAX_N];

void ch(int k) {
	int x0 = mp[0].first, y0 = mp[0].second;
	int x1 = x0 + fx[k][0], y1 = y0 + fx[k][1];
	int tm = a[x1][y1];
	swap(mp[0], mp[tm]), swap(a[x0][y0], a[x1][y1]);
	ans.push_back(w[pw][k]);
}

void rot() {
	pw = !pw, swap(height, width), swap(n, m);
	int tn = max(n, m);
	for (int i = 0; i < tn; i++) {
		for (int j = i + 1; j < tn; j++) {
			int tx1 = a[i][j], tx2 = a[j][i];
			swap(a[i][j], a[j][i]);
			swap(sol[i][j], sol[j][i]);
			mp[tx1] = make_pair(j, i);
			mp[tx2] = make_pair(i, j);
		}
	}
}

void reach(pair<int, int> &z0, int x, int y) {
	while (z0.first > x) ch(U);
	while (z0.first < x) ch(D);
	while (z0.second > y) ch(L);
	while (z0.second < y) ch(R);
}

bool gao() {
	if (n == 1 || m == 1) {
		reach(mp[0], n - 1, m - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != sol[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	while (true) {
		if (n - height < m - width) rot();
		pair<int, int> &z0 = mp[0];
		reach(z0, height, width);
		int chs = sol[height][m - 1];
		pair<int, int> &pl = mp[chs];
		reach(z0, pl.first, pl.second);
		if (pl.first != height) {
			while (pl.second != width) {
				ch(U), ch(L), ch(L), ch(D), ch(R); // u, l, l, d, r
			}
		} else {
			while (pl.second != width) {
				ch(D), ch(L), ch(L), ch(U), ch(R); // d, l, l, u, r
			}
		}
		if (z0.second == pl.second) {
			ch(R), ch(U); // r, u
		}
		while (pl.first != height) {
			ch(U), ch(L), ch(D), ch(R), ch(U); // u, l, d, r, u
		}
		reach(z0, z0.first + 1, z0.second);
		if (n - height == 2 && m - width == 2) {
			if (a[n - 2][m - 1] == sol[n - 2][m - 2]) {
				return false;
			} else {
				ch(U), ch(L), ch(D), ch(R); // u, l, d, r
				break;
			}
		}
		int now = width;
		while (now < m - 1) {
			int tnow = sol[height][now];
			pair<int, int> &th = mp[tnow];
			reach(z0, z0.first, th.second);
			if (th.first < z0.first) {
				if (now == m - 2) {
					ch(U), ch(L), ch(D), ch(D), ch(R); // u, l, d, d, r
					ch(U), ch(U), ch(L), ch(D), ch(R); // u, u, l, d, r
					ch(U), ch(L), ch(D), ch(R); // u, l, d, r
				} else if (th.second != m - 1) {
					ch(U), ch(R), ch(D); // u, r, d
				} else {
					ch(U), ch(L), ch(D), ch(R); // u, l, d, r
				}
			}
			reach(z0, th.first, z0.second);
			if (z0.second > th.second) {
				ch(D), ch(L); // d, l
			} else if (z0.second < th.second) {
				ch(D), ch(R); // d, r
			}
			while (th.second > now) {
				ch(L), ch(U), ch(R), ch(D), ch(L); // l, u, r, d, l
			}
			while (th.second < now) {
				ch(R), ch(U), ch(L), ch(D), ch(R); // r, u, l, d, r
			}
			while (th.first > pl.first) {
				ch(R), ch(U), ch(U), ch(L), ch(D); // r, u, u, l, d
			}
			now++;
		}
		height++;
	}
	if (sol[0][1] != 2) rot();
	return true;
}

int main() {
	n = 4, m = 4;
	mp.clear(), ans.clear();
	pw = 0, height = 0, width = 0;
	int tn = max(n, m);
	for (int i = 0; i < tn; i++) {
		for (int j = 0; j < tn; j++) {
			a[i][j] = -1, sol[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			sol[i][j] = i * m + j + 1;
			mp[a[i][j]] = make_pair(i, j);
		}
	}
	sol[n - 1][m - 1] = 0;
	if (gao()) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}

