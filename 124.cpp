#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10101;
struct Node {
	int x1, y1, x2, y2;
} p[MAX_N];
int x, y, n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
		if (p[i].x1 > p[i].x2) swap(p[i].x1, p[i].x2);
		if (p[i].y1 > p[i].y2) swap(p[i].y1, p[i].y2);
	}
	scanf("%d%d", &x, &y);
	int state = 0;
	for (int i = 0; !state && i < n; i++) {
		if (x == p[i].x2 && p[i].x1 == x) {
			state |= y >= p[i].y1 && y <= p[i].y2;
		} else if (y == p[i].y1 && p[i].y2 == y) {
			state |= x >= p[i].x1 && x <= p[i].x2;
		}
	}
	int ans = 0;
	for (int i = 0; !state && i < n; i++) {
		if (p[i].x1 == p[i].x2 && p[i].x1 < x) {
			ans ^= y >= p[i].y1 && y < p[i].y2;
		}
	}
	state |= ans << 1;
	if (state & 1) printf("BORDER\n");
	else if (state & 2) printf("INSIDE\n");
	else printf("OUTSIDE\n");
	return 0;
}
