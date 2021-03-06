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

const long long MOD = 998244353;
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

ll a[MAXN];
map <ll, ll> maps;

map <ll, ll> Maps;


long long Sqrt(long long x) {
  long long y = (long long) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return 0;
}

long long Cbrt(long long x) {
  long long y = (long long) (powl((long double) x, 1.0 / 3.0) + 0.5);
  while (y * y * y < x) {
    y++;
  }
  while (y * y * y > x) {
    y--;
  }
  if (y * y * y == x) {
    return y;
  }
  return 0;
}



int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
		a[i] = readInt();    	
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
    	ll S = Sqrt(a[i]);
    	ll SS = Sqrt(S);
    	int f = 0;
    	if (SS*SS*SS*SS==a[i]) {
    	    ///p^4 = 5
    		maps[SS] += 4;
    		continue;
    	} else if (S * S == a[i]) {
    		///p^2 = 3
    		maps[S] += 2;
    		continue;
    	}
    	ll C = Cbrt(a[i]);
    	///p^3 = 4
    	if (C*C*C == a[i]) {
    		maps[C] += 3;
    		continue;;
    	}
    	////	
		ll G = 1;
		for (int j = 1; j <= n; j++) {
			G = __gcd(a[j], a[i]);	
			if (G > 1 && G < a[i]) {
				break;
			}	
		}
		if (G > 1 && G < a[i]) {
			maps[G]++;
			maps[a[i]/G]++;
		} else {
			Maps[a[i]]++;
		}		
    }
    for (pair <ll, ll> kek : maps) {
    	ans = ans*((kek.S+1) % MOD);
    	ans %= MOD;
    }
    for (pair <ll, ll> kek : Maps) {
    	ans = ans*((kek.S+1)%MOD) ;
    	ans %= MOD;
    	ans = ans*((kek.S+1)%MOD);
    	ans %= MOD;
    }
    cout << ans;
    return 0;
}