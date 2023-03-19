
#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7, N = 1e5 + 5;
vector<pair<ll, ll>> e[N];
ll low[N], dfn[N], thisTime, cnt, sz[N], val;
int n, m;

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++thisTime;
	for (auto [x, w] : e[u]) {
		if (x == fa)continue;
		if (!dfn[x]) {
			tarjan(x, u);
			sz[u] += sz[x];
			low[u] = min(low[u], low[x]);
			if (low[x] > dfn[u]) {
				if (((sz[x] - 1) / 2) % 2 == 0) {
					val = min(val, w);
				}
			} else {
				val = min(val, w);
			}
		} else {
			val = min(val, w);
			low[u] = min(low[u], low[x]);
		}
		if (dfn[u] < dfn[x]) cnt++;
	}
}
void solve() {
	ll ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		ll x, y, w;
		cin >> x >> y >> w;
		e[x].push_back({y, w});
		e[y].push_back({x, w});
		sz[x] ++;
		sz[y] ++;
		ans += w;
	}
	for (int i = 1; i <= n; i ++) {
		if (!dfn[i]) {
			val = 0x3f3f3f3f;
			cnt = 0;
			tarjan(i, 0);
			if (cnt & 1) ans -= val;
		}
	}
	cout << ans << endl;
}

signed main() {
	OST;
	int T = 1;
	// cin >> T;
	while (T--) { solve(); }
	return 0;
}
