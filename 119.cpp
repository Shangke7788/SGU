#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

set< pair<int, int> > st;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	a %= n, b %= n;
	st.clear();
	int nx = 0, ny = 0, cnt = 0;
	while (st.find(make_pair(nx, ny)) == st.end()) {
		st.insert(make_pair(nx, ny));
		cnt++;
		nx += a, ny += b;
		if (nx >= n) nx -= n;
		if (ny >= n) ny -= n;
	}
	printf("%d\n", cnt);
	for (set< pair<int, int> >::iterator iter = st.begin(); iter != st.end(); iter++) {
		printf("%d %d\n", iter->first, iter->second);
	}
	return 0;
}
