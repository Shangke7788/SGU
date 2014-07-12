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

const double EPS = 1.0e-8;
const int MAX_N = 10101;
pair<double, double> p[MAX_N];
int n;
inline int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &p[i].first, &p[i].second);
	}
	bool ok = true;
	double nx = 0, ny = 0;
	int xi = 1;
	for (int i = 0; i < n - 1; i++) {
		xi = -xi;
		nx = 2 * p[i].first - nx;
		ny = 2 * p[i].second - ny;
	}
	pair<double, double> o;
	if (xi < 0) {
		ok = !sgn(ny - 2 * p[n - 1].second) && !sgn(nx - 2 * p[n - 1].first);
		o.first = o.second = 0;
	} else {
		o.first = (2 * p[n - 1].first - nx) / 2;
		o.second = (2 * p[n - 1].second - ny) / 2;
	}
	if (!ok) {
		printf("NO\n");
	} else {
		printf("YES\n");
		printf("%.3lf %.3lf\n", o.first, o.second);
		for (int i = 0; i < n - 1; i++) {
			printf("%.3lf %.3lf\n", 
					o.first = p[i].first * 2 - o.first,
					o.second = p[i].second * 2 - o.second);
		}
	}
	return 0;
}
