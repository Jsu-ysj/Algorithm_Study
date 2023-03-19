#include <bits/stdc++.h>

using namespace std;
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
	}
	if (n & 1) {
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
	}
}

signed main() {
	OST;
	int T = 1;
	cin >> T;
	while (T--) { solve(); }
	return 0;
}
