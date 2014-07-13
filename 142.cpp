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

const int MAX_N = 505050;
char s[MAX_N];
int n;
bool has[MAX_N << 2];

int main() {
	scanf("%d%s", &n, s);
	for (int i = 1; i <= 22; i++) {
		int t = (1 << i) - 1;
		int now = 0;
		fill(has, has + t + 2, false);
		for (int j = 0; j < i - 1; j++) {
			now = (now << 1) | (s[j] - 'a');
		}
		for (int j = i - 1; j < n; j++) {
			now = ((now << 1) | (s[j] - 'a')) & t;
			has[now] = true;
		}
		int v = -1;
		for (int j = 0; j <= t; j++) {
			if (!has[j]) {
				v = j;
				break;
			}
		}
		if (~v) {
			printf("%d\n", i);
			for (int j = i - 1; j >= 0; j--) {
				s[j] = 'a' + (v & 1);
				v >>= 1;
			}
			s[i] = 0;
			printf("%s\n", s);
			break;
		}
	}
	return 0;
}
