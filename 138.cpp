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
#include <queue>
using namespace std;
typedef long long lint;

const int MAX_N = 111;
vector<int> ans;
int n, d[MAX_N], sum;
vector<int> a[MAX_N];

void dfs(int x) {
	if (d[x] == 0) {
		ans.push_back(x);
		return;
	}
	int mx = 0, u = -1;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			if (d[i] > mx) {
				mx = d[u = i];
			}
		}
	}
	ans.push_back(x);
	d[u]--, d[x]--, dfs(u);
}

int main() {
	ans.clear();
	scanf("%d", &n);
	sum = 0;
	int vv = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i);
		sum += d[i];
		vv += d[i] & 1;
		a[i].clear();
	}
	printf("%d\n", sum >> 1);
	while (vv != 2) {
		int mn = 100000, v = -1;
		for (int i = 1; i <= n; i++) {
			if (d[i] & 1) {
				if (mn > d[i]) {
					mn = d[v = i];
				}
			}
		}
		if (v == -1) {
			for (int i = 1; i <= n; i++) {
				if (d[i]) {
					if (mn > d[i]) {
						mn = d[v = i];
					}
				}
			}
		}
		int mx = 0, u = -1;
		for (int i = n; i >= 1; i--) {
			if (d[i] > mx) {
				mx = d[u = i];
			}
		}
		a[u].push_back(v);
		d[u]--, d[v]--;
		if (d[v] & 1) vv++; else vv--;
		if (d[u] & 1) vv++; else vv--;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] & 1) {
			dfs(i);
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size() - 1; i++) {
		int x = ans[i];
		while ((int)a[x].size()) {
			printf("%d %d\n", x, a[x].back());
			a[x].pop_back();
		}
		printf("%d %d\n", ans[i + 1], x);
	}
	while ((int)a[ans.back()].size()) {
		printf("%d %d\n", ans.back(), a[ans.back()].back());
		a[ans.back()].pop_back();
	}
	return 0;
}
