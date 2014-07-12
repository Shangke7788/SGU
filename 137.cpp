#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
int a[MAX_N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int w = k / n;
	k %= n;
	int t = 1;
	while ((t * k) % n != n - 1) t++;
	for (int i = 1; i <= k; i++) {
		a[(i * t) % n] = 1;
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i] + w, " \n"[i == n - 1]);
	}
	return 0;
}
