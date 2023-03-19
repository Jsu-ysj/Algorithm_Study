#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7, MAXN = 1e7 + 5;
int a[20];
vector<pair<int, int>> v[20];
int dp[MAXN];
void init() {
	v[0].push_back({1, 2});
	v[0].push_back({4, 9});
	v[0].push_back({3, 7});


	v[1].push_back({4, 8});
	v[1].push_back({5, 10});

	v[2].push_back({5, 9});
	v[2].push_back({6, 11});
	v[2].push_back({1, 0});

	v[3].push_back({4, 5});
	v[3].push_back({8, 13});

	v[4].push_back({8, 12});
	v[4].push_back({9, 14});
	v[4].push_back({5, 6});

	v[5].push_back({4, 3});
	v[5].push_back({9, 13});
	v[5].push_back({10, 15});

	v[6].push_back({5, 4});
	v[6].push_back({10, 14});

	v[7].push_back({3, 0});
	v[7].push_back({8, 9});
	v[7].push_back({12, 16});

	v[8].push_back({4, 1});
	v[8].push_back({9, 10});
	v[8].push_back({13, 17});

	v[9].push_back({4, 0});
	v[9].push_back({5, 2});
	v[9].push_back({10, 11});
	v[9].push_back({14, 18});
	v[9].push_back({13, 16});
	v[9].push_back({8, 7});

	v[10].push_back({5, 1});
	v[10].push_back({9, 8});
	v[10].push_back({14, 17});

	v[11].push_back({6, 2});
	v[11].push_back({10, 9});
	v[11].push_back({15, 18});

	v[12].push_back({8, 4});
	v[12].push_back({13, 14});

	v[13].push_back({8, 3});
	v[13].push_back({9, 5});
	v[13].push_back({14, 15});

	v[14].push_back({13, 12});
	v[14].push_back({9, 4});
	v[14].push_back({10, 6});

	v[15].push_back({14, 13});
	v[15].push_back({10, 5});

	v[16].push_back({12, 7});
	v[16].push_back({13, 9});
	v[16].push_back({17, 18});

	v[17].push_back({13, 8});
	v[17].push_back({14, 10});

	v[18].push_back({17, 16});
	v[18].push_back({14, 9});
	v[18].push_back({15, 11});
}
void solve() {
	init();
	int sum = 0;
	for (int i = 0; i <= 18; i ++) cin >> a[i], sum += a[i];
	// 方法一
	// for (int s = 0; s <= (1 << 19); s ++) {
	// 	for (int j =  0; j < 19; j  ++) {
	// 		if (s >> j & 1) {
	// 			dp[s] = max(dp[s - (1 << j)], dp[s]);
	// 			for (auto x : v[j]) {
	// 				if (s >> x.first & 1 && !(s >> x.second & 1)) {
	// 					int now = s - (1 << j) - (1 << x.first) + (1 << x.second);
	// 					dp[s] = max(dp[s], dp[now] + a[x.first]);
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	//方法二
	vector<int> vis((1 << 19), 0);
	queue<int> q;
	for (int i = 0; i <= (1 << 19); i ++) dp[i] = -1;
	for (int i = 0; i <= 18; i ++) dp[(1 << i)] = 0, q.push((1 << i)), vis[(1 << i)] = 1;
	q.push(0);
	dp[0] = 0;
	vis[0] = 1;
	while (q.size()) {
		int s = q.front();
		q.pop();
		for (int j =  0; j < 19; j  ++) {
			if (!(s >> j & 1)) {
				dp[s + (1 << j)] = max(dp[s + (1 << j)], dp[s]);
				if (!vis[s + (1 << j)]) {
					vis[s + (1 << j)] = 1;
					q.push(s + (1 << j));

				}
			}
			if (s >> j & 1) {
				for (auto x : v[j]) {
					if (!(s >> x.first & 1) && !(s >> x.second & 1)) {
						int now = s + (1 << x.first) + (1 << x.second) - (1 << j);
						dp[now] = max(dp[now], dp[s] + a[x.first]);
						if (!vis[now]) {
							vis[now] = 1;
							q.push(now);
						}
					}
				}
			}
		}

	}
	int T;
	cin >> T;
	while (T --) {
		int cnt = 0, num = 0;
		for (int i = 1; i <= 5; i ++) {
			string s;
			cin >> s;
			for (int j = 0; j < (int)s.size(); j ++) {
				if (s[j] == '#') {
					num += (1 << cnt);
				}
				cnt++;
			}
		}
		// cout << num << endl;
		cout << dp[num] << endl;
	}

}

signed main() {
	OST;
	int T = 1;
	// cin >> T;
	while (T--) { solve(); }
	return 0;
}
