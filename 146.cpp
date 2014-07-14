#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <math.h>
using namespace std;
typedef long long lint;

const int MAX_N = 20202;
double l;
int n, L, t[MAX_N], v[MAX_N];

double dmod(double a, double b) {
	int c = floor(a / b);
	return a - b * c;
}

int main() {
	scanf("%lf%d", &l, &n);
	L = round(l * 10000);
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", t + i, v + i);
		s = (s + 1LL * t[i] * v[i] * 10000) % L;
	}
	if (s < 0) s += L;
	if (2 * s > L) s = L - s;
	printf("%.4lf\n", s / 10000.0);
	return 0;
}
