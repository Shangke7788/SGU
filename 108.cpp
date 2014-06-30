#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int N, K, ans[5555];
unsigned int a[10000005 / 32 + 5];
struct Node {
	int a, id;
	bool operator < (const Node& o) const {
		return a < o.a;
	}
} s[5555];

inline int get_digit(int x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &s[i].a);
		s[i].id = i;
	}
	sort(s, s + K);
	int now = 0;
	for (int i = 1; i <= N; i++) {
		int val = i + get_digit(i);
		a[val >> 5] |= 1U << (val & 31);
	}
	int res = 0, j = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i >> 5] & (1U << (i & 31))) {
		} else {
			res++;
			while (j < K && res == s[j].a) {
				ans[s[j].id] = i;
				j++;
			}
		}
	}
	printf("%d\n", res);
	for (int i = 0; i < K; i++) {
		printf("%d%c", ans[i], " \n"[i == K - 1]);
	}
	return 0;
}
