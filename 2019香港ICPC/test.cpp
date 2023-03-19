#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7, N = 1e5 + 10, inf = 1e18;
int vis1[N], vis2[N], num1[N], num2[N];

struct node {
	int x, y, w;
} a[2 * N];
vector<pair<int, int>> e[N];


void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int x, y, w;
		cin >> x >> y >> w;
		a[i].x = x, a[i].y = y, a[i].w = w;
		e[x].push_back({y, w});
		e[y].push_back({x, w});
	}
	ll ans = 0;
	for (int i = 0; i <= 30; i ++) {
		vector<int> st;
		for (int j = 1; j <= m; j ++) {
			if (a[j].w >> i & 1) {
				st.push_back(a[j].x);
				st.push_back(a[j].y);
			}
		}

		for (int j = 1; j <= n; j ++) vis1[j] = 0, vis2[j] = 0;
		for (int  j = 1; j <= n; j ++) num1[j] = 0, num2[j] = 0;
		for (auto x : st) {
			if (!vis1[x]) {
				ll res1 = (1 << i), res2 = 0, flag1 = 1, flag2 = 1;
				queue<int> q;
				q.push(x);
				vis1[x] = 1;
				num1[x] = 1;
				while (q.size()) {
					int now = q.front();
					q.pop();
					for (auto [v, w] : e[now]) {
						if (vis1[v]) {
							if ((w >> i & 1) == 0) {
								if (num1[now] == num1[v]) continue;
								flag1 = 0;
								// cout << x << " " << v << endl;
								break;
							} else {
								if (num1[now] != num1[v]) continue;
								// cout << x << " " << v << endl;
								flag1 = 0;
								break;
							}
						} else {
							vis1[v] = 1;
							q.push(v);
							num1[v] = (w >> i & 1)^num1[now];
							res1 += num1[v] * (1 << i);
						}
					}
				}

				// 2
				q.push(x);
				vis2[x] = 1;
				num2[x] = 0;
				while (q.size()) {
					int now = q.front();
					q.pop();
					for (auto [v, w] : e[now]) {
						if (vis2[v]) {
							if ((w >> i & 1) == 0) {
								if (num2[now] == num2[v]) continue;
								flag2 = 0;
								break;
							} else {
								if (num2[now] != num2[v]) continue;
								flag2 = 0;
								break;
							}
						} else {
							vis2[v] = 1;
							q.push(v);
							num2[v] = (w >> i & 1)^num2[now];
							res2 += num2[v] * (1 << i);
						}
					}
				}
				if (flag2 && flag1) {
					// cout << res1 << " " << res2 << endl;
					ans += min(res2, res1);
				} else if (flag1) {
					ans += res1;
				} else if (flag2) {
					ans += res2;
				} else {
					cout << -1 << endl;
					return;
				}
			}

		}
		// cout << ans << endl;
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
