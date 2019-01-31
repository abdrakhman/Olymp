/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;

long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}


pair<int, int> a[MAXN];
pair<int, int> b[MAXN];


map<int, pair <int, int> > maps;

void go_ans(int l1, int r1, int l2, int r2) {
	cout << r1 - l1 + 1 << endl;
	for (int i = l1; i <= r1; i ++) {
		cout << a[i].S << ' ';
	}	
	cout << endl << r2 - l2 + 1 << endl;
	for (int i = l2; i <= r2; i++) {
		cout << b[i].S << ' ';
	}
	exit(0);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = {readInt(), i};
    }
    for (int i = 1; i <= n; i++) {
    	b[i] = {readInt(), i};
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
	int diff = a[1].F;
	maps[diff] = {1, 0};
	diff -= b[1].F;
	maps[diff] = {1, 1};
	if (diff == 0) {
		go_ans(1, 1, 1, 1);
	}
	int l1 = 1;
    int l2 = 1;
	while (l1 < n || l2 < n) {
		if (diff < 0) {
			diff += a[l1 + 1].F;
			l1++;
		} else {
			diff -= b[l2 + 1].F;
			l2++;
		}	
		if (diff == 0) {
			go_ans(1, l1, 1, l2);
		}
		if (maps.count(diff)) {
			int ans_l = maps[diff].F;
			int ans_r = maps[diff].S;
			if (ans_l > l1) swap(ans_l, l1);
			if (ans_r > l2) swap(ans_r, l2);
			go_ans(ans_l + 1, l1, ans_r + 1, l2);
		}
		maps[diff] = {l1, l2};
	}
    return 0;
}