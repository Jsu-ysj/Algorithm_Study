#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7;
vector<int> ans;
void dfs(int n, int k) {
	if (n) {
		n --;
		dfs(n / k, k);
		ans.push_back(n % k);
	}
}
void solve() {
	int k, n, num = 9;
	cin >> k >> n;
	vector<int> a(k);
	ans.clear();
	for (int i = k - 1; i >= 0; i --) {
		a[i] = num --;
	}
	dfs(n, k);
	for (auto x : ans) {
		cout << a[x];
	}
	cout << endl;
}

signed main() {
	OST;
	int T = 1;
	cin >> T;
	while (T--) { solve(); }
	return 0;
}
