#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;

bool check(int n) {
    if (n <= 2) { return false; }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (check(n) && (check(n - 6) || check(n + 6))) {
        cout << "Yes" << endl;
        if (check(n - 6)) {
            cout << n - 6 << endl;
        } else {
            cout << n + 6 << endl;
        }
        return;
    }
    cout << "No" << endl;
    for (int i = n;; i++) {
        if (check(i) && (check(i - 6) || check(i + 6))) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
