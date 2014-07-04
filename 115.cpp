#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int a[390];
int d[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int get_day(int m, int d) {
	if (m < 0 || m > 12) return -1;
	m--;
	if (d < 0 || d > ::d[m]) return -1;
	int ss = 0;
	for (int i = 0; i < m; i++) {
		ss += ::d[i];
	}
	ss += d - 1;
	return ss;
}

int main() {
	a[0] = 1;
	for (int i = 1; i < 390; i++) {
		a[i] = a[i - 1] + 1;
		if (a[i] > 7) a[i] -= 7;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	if (get_day(m, n) == -1) {
		printf("Impossible\n");
	} else {
		printf("%d\n", a[get_day(m, n)]);
	}
	return 0;
}
