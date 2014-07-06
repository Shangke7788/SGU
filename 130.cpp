#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 35;
lint a[MAX_N];
int n;

int main() {
	a[0] = a[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		for (int j = 0; j < i; j++) {
			a[i] += a[j] * a[i - j - 1];
		}
	}
	scanf("%d", &n);
	printf("%I64d %d\n", a[n], n + 1);
	return 0;
}
