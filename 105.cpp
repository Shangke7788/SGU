#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
	int n;
	scanf("%d", &n);
	int ans = n / 3 * 2;
	if (n % 3 == 2) {
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
