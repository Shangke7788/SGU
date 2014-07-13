#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long lint;

int x1, x2, P, K;
pair<int, int> ans;

map< int, pair<int, int> > mp;
queue<int> q;

int main() {
	scanf("%d%d%d%d", &x1, &x2, &P, &K);
	int d = __gcd(x1, x2);
	if (P % d) {
		printf("NO\n");
	} else {
		x1 /= d, x2 /= d, P /= d;
		q.push(0), mp[0] = make_pair(0, 0);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			int y = 0;
			if (x > P) {
				y = x - (int)x1;
				if (mp.find(y) == mp.end()) {
					q.push(y);
					mp[y] = make_pair(mp[x].first - 1, mp[x].second);
				}
				y = x - (int)x2;
				if (mp.find(y) == mp.end()) {
					q.push(y);
					mp[y] = make_pair(mp[x].first, mp[x].second - 1);
				}
			} else {
				y = x + (int)x1;
				if (mp.find(y) == mp.end()) {
					q.push(y);
					mp[y] = make_pair(mp[x].first + 1, mp[x].second);
				}
				y = x + (int)x2;
				if (mp.find(y) == mp.end()) {
					q.push(y);
					mp[y] = make_pair(mp[x].first, mp[x].second + 1);
				}
			}
			if (mp.find(P) != mp.end()) break;
		}
		ans = mp[P];
		if (K + ans.first + ans.second & 1) {
			if (ans.first > 0) {
				ans.first -= x2;
				ans.second += x1;
			} else {
				ans.first += x2;
				ans.second -= x1;
			}
		}
		if (K < abs(ans.first) + abs(ans.second)) {
			printf("NO\n");
			return 0;
		}
		if (K + ans.first + ans.second & 1) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		int x = K - abs(ans.first) - abs(ans.second) >> 1;
		if (ans.first >= 0 && ans.second >= 0) {
			printf("%d %d %d %d\n", ans.first + x, x, ans.second, 0);
		} else if (ans.first >= 0 && ans.second < 0) {
			printf("%d %d %d %d\n", ans.first + x, x, 0, -ans.second);
		} else if (ans.first < 0 && ans.second >= 0) {
			printf("%d %d %d %d\n", x, x - ans.first, ans.second, 0);
		} else {
			printf("%d %d %d %d\n", x, x - ans.first, 0, -ans.second);
		}
	}
	return 0;
}
