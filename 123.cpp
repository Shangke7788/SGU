#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 45;
lint dp[MAX_N], sum[MAX_N];

int main() {
	dp[1] = dp[2] = 1;
	sum[1] = 1, sum[2] = 2;
	for (int i = 3; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		sum[i] = sum[i - 1] + dp[i];
	}
	int k;
	scanf("%d", &k);
	printf("%I64d\n", sum[k]);
	return 0;
}
