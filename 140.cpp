#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long lint;

const int MAX_N = 111;
int n, a[MAX_N], x[MAX_N], b, p;
int ans[MAX_N], d[MAX_N];

int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

int gao(int i, int d) {
	int p = ::p / d, a = ::a[i] / d;
	int x, y;
	exgcd(a, p, x, y);
	return (x % p + p) % p;
}

void calc() {
	for (int i = 0; i < n; i++) {
		x[i] = gao(i, d[i]);
	}
}
queue<int> q;
int vis[10101], last[10101];

int main() {
	scanf("%d%d%d", &n, &p, &b);
	int v = -1;
	int d = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		a[i] %= p;
		::d[i] = __gcd(a[i], p);
		d = __gcd(d, ::d[i]);
	}
	if (b % d) {
		printf("NO\n");
	} else {
		printf("YES\n");
		calc();
		vis[b] = 1, q.push(b), last[b] = -1;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < n; i++) {
				int y = x + p - ::d[i];
				if (y >= p) y -= p;
				if (vis[y]) continue;
				q.push(y), vis[y] = 1, last[y] = i;
			}
			if (vis[0]) break;
		}
		int now = 0;
		while (~last[now]) {
			ans[last[now]] += x[last[now]];
			now += ::d[last[now]];
			if (now >= p) now -= p;
		}
		for (int i = 0; i < n; i++) {
			printf("%d%c", ans[i], " \n"[i == n - 1]);
		}
	}
	return 0;
}
