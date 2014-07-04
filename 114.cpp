#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 15555;
int n, sum[MAX_N];
pair<double, int> p[MAX_N];

int main() {
	scanf("%d", &n);
	int ss = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lf%d", &p[i].first, &p[i].second);
		ss += p[i].second;
	}
	sort(p + 1, p + n + 1);
	sum[0] = 0;
	double ans = -1;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + p[i].second;
		if (sum[i - 1] <= ss / 2 && sum[i] > ss / 2) {
			ans = p[i].first;
			break;
		}
	}
	printf("%.5lf\n", ans);
	return 0;
}
