#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10001;
int pr[MAX_N], wh[MAX_N], pn, np, n;
vector<int> ans;

int step[MAX_N], q[MAX_N], last[MAX_N], qn;

int main() {
	scanf("%d", &n);
	if (n == 1 || n == 2 || n == 4 || n == 7) {
		printf("0\n");
		return 0;
	}
	pn = 0;
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		if (!pr[i]) {
			wh[pn++] = i;
		} else {
			continue;
		}
		for (int j = i * 2; j < MAX_N; j += i) {
			pr[j] = 1;
		}
	}
	np = 0;
	for (int i = 0; wh[i] - 1 < pn; i++) {
		pr[np++] = wh[wh[i] - 1];
	}
	last[n] = -1;
	step[n] = 1;
	q[qn++] = n;
	for (int i = 0; i < qn; i++) {
		for (int j = 0; j < np; j++) {
			if (q[i] < pr[j]) break;
			int x = q[i] - pr[j];
			if (step[x]) continue;
			step[x] = 1;
			last[x] = pr[j];
			q[qn++] = x;
			if (x == 0) break;
		}
		if (step[0]) break;
	}
	ans.clear();
	int x = 0;
	while (last[x] != -1) {
		ans.push_back(last[x]);
		x += last[x];
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
	}
	return 0;
}
