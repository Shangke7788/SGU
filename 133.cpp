#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 16767;
pair<int, int> a[MAX_N];
int n, p, ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	ans = 0;
	p = -1;
	for (int i = 0; i < n; i++) {
		if (p > a[i].second) {
			ans++;
		} else {
			p = a[i].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}
