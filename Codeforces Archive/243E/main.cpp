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
#define all(v) (v).begin(), (v).end()


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
typedef pair<int, int> pii;


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


const int N = 3333;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

string dirs = "UDRL";

int directiony[N];
int directionx[N];


ll curx = 5000000001LL, cury = 5000000001LL;
vector <ll> xler;
vector <ll> yler;
	
void add() {
	xler.pb(curx);
	xler.pb(curx-1);
	xler.pb(curx+1);
	yler.pb(cury);
	yler.pb(cury-1);
	yler.pb(cury+1);
}

int used[N][N];
int H, W;

void dfs(int x, int y) {
	used[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if ((0 <= tmpx && tmpx < H) && (0 <= tmpy && tmpy < W) && used[tmpx][tmpy] == 0) {
			dfs(tmpx, tmpy);
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
	add();
    for (int i = 0; i < n; i++) {
		char x;
		int y;
		cin >> x >> y;
		for (int j = 0; j < 4; j++) {
			if (dirs[j] == x) {
				directionx[i] = dx[j] * y;
				directiony[i] = dy[j] * y;
				curx += directionx[i];
				cury += directiony[i];
				add();
			}
		}				    
    }
	sort(xler.begin(), xler.end());
	sort(yler.begin(), yler.end()); 	
	xler.resize(unique(xler.begin(), xler.end()) - xler.begin());
	yler.resize(unique(yler.begin(), yler.end()) - yler.begin());
	H = xler.size();
	W = yler.size();
	curx = 5000000001LL;
	cury = 5000000001LL;
	ll compx = lower_bound(xler.begin(), xler.end(), curx) - xler.begin();
	ll compy = lower_bound(yler.begin(), yler.end(), cury) - yler.begin();

	for (int i = 0; i < n; i++) {
		ll tmpx = curx + directionx[i];
		ll tmpy = cury + directiony[i];
		ll tmpcompx = lower_bound(all(xler), tmpx) - xler.begin();
		ll tmpcompy = lower_bound(all(yler), tmpy) - yler.begin();
		for (int j = min(tmpcompx, compx); j <= max(tmpcompx, compx); j++) {
			for (int k = min(tmpcompy, compy); k <= max(tmpcompy, compy); k++) {
				used[j][k] = 1;
			}
		}
		curx = tmpx;
		cury = tmpy;
		compx = tmpcompx;
		compy = tmpcompy;
	}
	dfs(0, 0);
	ll res = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (used[i][j] != 2) {
				res += (xler[i + 1] - xler[i]) * (yler[j + 1] - yler[j]);
			}
		}
	}
	cout << res;
    return 0;
}