#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10101;
int pr[MAX_N], n, m, k;
map<int, int> mp;
map<int, int> yy;

int main() {
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		if (!pr[i]) {
			for (int j = i; j < MAX_N; j += i) {
				pr[j] = i;
			}
		}
	}
	mp.clear();
	scanf("%d%d%d", &n, &m, &k);
	while (pr[k] != 1) {
		mp[pr[k]]++;
		k /= pr[k];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		yy.clear();
		while (pr[x] != 1) {
			yy[pr[x]] += m;
			x /= pr[x];
		}
		int ok = 1;
		for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
			if (yy[iter->first] < iter->second) {
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	printf("%d\n", ans);
	return 0;
}
