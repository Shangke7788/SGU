#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int p, n, num[10];

int main() {
	scanf("%d%d", &p, &n);
	for (int i = 0; i < n; i++) {
		char s[10];
		scanf("%s", s);
		num[s[0] - '0']++;
	}
	int ans = 2;
	for (int i = 0; i < 10; i++) {
		ans += (num[i] + p - 1) / p;
	}
	printf("%d\n", ans);
	return 0;
}
