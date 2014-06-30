#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
	/*
	for (int i = 1; i < 1000000000; i++) {
		lint s = 1LL * i * i;
		if ((s - 987654321) % 1000000000 == 0) {
			printf("%d %I64d\n", i, s);
		}
	}
	*/
	int n;
	scanf("%d", &n);
	if (n <= 8) {
		printf("0\n");
	} else if (n == 9) {
		printf("8\n");
	} else {
		printf("72");
		n -= 10;
		while (n--) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
