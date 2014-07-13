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

int x, y;
double z;

int main() {
	scanf("%d%d%lf", &x, &y, &z);
	double p = (y - x) * 60.0;
	double s = p * p;
	double s1 = (p - z) * (p - z);
	printf("%.7lf\n", 1.0 - s1 / s);
	return 0;
}
