#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7, N = 505, inf = 1e18;

ll dp[N][N], tmp[N][N];

struct node {
	ll v1, t1, v2, t2;
};
node a[N];
ll n, m1, m2;


void solve() {
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].v1 >> a[i].t1 >> a[i].v2 >> a[i].t2;
	}
	sort(a + 1, a + n + 1, [&](node a, node b) {
		return a.v1 < b.v1;
	});
	for (int i = 0; i <= m1; i ++) {
		for (int j = 0; j <= m2; j ++) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = m1; j >= 0;  j--) {
			for (int k = m2; k >= 0; k --) {
				tmp[j][k] = dp[j][k];
			}
		}

		for (int j = m1; j >= 0;  j--) {
			for (int k = m2; k >= 0; k --) {
				if (dp[j][k] != inf) {
					if (j < m1) {
						ll minj = j + a[i].v1, mink = k;
						if (minj > m1) {
							mink += minj - m1;
							mink = min(m2, mink);
							minj = m1;
						}
						// cout << j << " " << k << endl;
						tmp[minj][mink] = min(tmp[minj][mink], dp[j][k] + a[i].t1);
					}
					ll mink = min(m2, a[i].v2 + k);
					tmp[j][mink] = min(tmp[j][mink], dp[j][k] + a[i].t2);
				}
			}

		}

		for (int j = m1; j >= 0; j --) {
			for (int k = m2; k >= 0; k --) {
				dp[j][k] = tmp[j][k];
			}
		}
	}
	if (dp[m1][m2] != 0 && dp[m1][m2] != inf) {
		cout << dp[m1][m2] << endl;
	} else {
		cout << -1 << endl;
	}
}

signed main() {
	OST;
	int T = 1;
	// cin >> T;
	while (T--) { solve(); }
	return 0;
}
