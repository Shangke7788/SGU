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

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", 1 + 1LL * n * (n + 1) / 2);
	return 0;
}
