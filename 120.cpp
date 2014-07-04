#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 155;
const double EPS = 1.0e-6;

inline int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int n, n1, n2;
struct Point {
	double x, y;
	Point() {}
	Point(double x, double y): x(x), y(y) {}
	Point &operator = (const Point& o) {
		x = o.x, y = o.y;
		return *this;
	}
	Point operator + (const Point& o) {
		Point ans = Point(0.0, 0.0);
		ans.x = x + o.x;
		ans.y = y + o.y;
		return ans;
	}
	Point operator - (const Point& o) {
		Point ans = Point(0.0, 0.0);
		ans.x = x - o.x;
		ans.y = y - o.y;
		return ans;
	}
	Point operator * (const double d) {
		return Point(d * x, d * y);
	}
	double len() {
		return sqrt(x * x + y * y);
	}
} p[MAX_N], a, b;

const double PI = acos(-1.0);

vector<Point> ans;
vector<Point> res;

int main() {
	scanf("%d%d%d", &n, &n1, &n2);
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	--n1, --n2;
	if (n1 > n2) {
		swap(n1, n2);
		swap(a, b);
	}
	Point mid = (a + b) * 0.5;
	Point fx = Point(b.y - a.y, a.x - b.x);
	double dab = (b - a).len() * 0.5;
	double R = 0.0;
	if ((n2 - n1) * 2 <= n) {
		double tx = PI * (n2 - n1) / n;
		double L = dab / tan(tx);
		fx = fx * (L / fx.len());
		R = dab / sin(tx);
	} else {
		fx = fx * -1.0;
		double tx = PI * (n + n1 - n2) / n;
		double L = dab / tan(tx);
		fx = fx * (L / fx.len());
		R = dab / sin(tx);
	}
	Point O = mid + fx;
	ans.clear();
	double delta = 2.0 * PI / n;
	double start = atan2(a.y - O.y, a.x - O.x);
	for (int i = 0; i < n; i++) {
		ans.push_back(O + Point(cos((n - i - 1) * delta + start), sin((n - i - 1) * delta + start)) * R);
	}
	int s = 0, e = n1;
	for (int i = 0; i < n; i++) {
		if (sgn(a.x - ans[i].x) == 0 && sgn(a.y - ans[i].y) == 0) {
			s = i;
			break;
		}
	}
	res = vector<Point>(n, Point());
	res[e++] = ans[s++];
	e %= n, s %= n;
	while (e != n1) {
		res[e++] = ans[s++];
		e %= n, s %= n;
	}
	for (int i = 0; i < n; i++) {
		printf("%.6lf %.6lf\n", res[i].x, res[i].y);
	}
	return 0;
}
