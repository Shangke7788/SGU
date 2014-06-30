#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint exgcd(lint a, lint b, lint& x, lint& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	lint d = exgcd(b, a % b, x, y);
	lint t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

int main() {
	lint a, b, c, x1, x2, y1, y2;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &x1, &x2, &y1, &y2);
	if (x1 > x2 || y1 > y2) {
		printf("0\n");
		return 0;
	}
	lint x, y, d = exgcd(abs(a), abs(b), x, y);
	if (a == 0 && b == 0) {
		if (c != 0) {
			printf("0\n");
		} else {
			printf("%I64d\n", (x2 - x1 + 1) * (y2 - y1 + 1));
		}
	} else if (c % d != 0) {
		printf("0\n");
	} else if (a == 0) {
		lint t = -c / b;
		if (t >= y1 && t <= y2) {
			printf("%I64d\n", x2 - x1 + 1);
		} else {
			printf("0\n");
		}
	} else if (b == 0) {
		lint t = -c / a;
		if (t >= x1 && t <= x2) {
			printf("%I64d\n", y2 - y1 + 1);
		} else {
			printf("0\n");
		}
	} else {
		if (a < 0) x = -x;
		if (b < 0) y = -y;
		x = -x * c / d, y = -y * c / d;
		lint dx = abs(b / d), dy = abs(a / d);
		lint p = (x % dx - x1 % dx + 2 * dx) % dx;
		lint lx = x1 + p;
		p = (x % dx - x2 % dx + 2 * dx) % dx;
		lint rx = x2 + p - (p == 0 ? 0 : dx);
		if (lx > rx) {
			printf("0\n");
		} else {
			lint ly = (-c - a * lx) / b, ry = (-c - a * rx) / b;
			if (ly > ry) swap(ly, ry);
			if (ly > y2 || ry < y1) printf("0\n");
			else {
				if (ly < y1) {
					p = (y % dy - y1 % dy + 2 * dy) % dy;
					ly = y1 + p;
				}
				if (ry > y2) {
					p = (y % dy - y2 % dy + 2 * dy) % dy;
					ry = y2 + p - (p == 0 ? 0 : dy);
				}
				printf("%I64d\n", (ry - ly) / dy + 1);
			}
		}
	}
	return 0;
}
