#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
#define int long long
#define lowbit(x) ((-x) & x)
const int N = 1e3 + 5;
int t1[N][N];
int t2[N][N];
int t3[N][N];
int t4[N][N];
int n, m, q;

void add(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            t1[i][j] += val;
            t2[i][j] += val * x;
            t3[i][j] += val * y;
            t4[i][j] += val * x * y;
        }
    }
}

void real_add(int x1, int y1, int x2, int y2, int v) {
    add(x1, y1, v);
    add(x1, y2 + 1, -v);
    add(x2 + 1, y1, -v);
    add(x2 + 1, y2 + 1, v);
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += (x + 1) * (y + 1) * t1[i][j];
            res -= (y + 1) * t2[i][j];
            res -= (x + 1) * t3[i][j];
            res += t4[i][j];
        }
    }
    return res;
}

int real_query(int x1, int y1, int x2, int y2) { return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1); }

void solve() {
    cin >> n >> m >> q;
    while (q--) {
        int op, x1, y1, x2, y2;
        cin >> op >> x1 >> y1 >> x2 >> y2;
        // cout << q << endl;
        switch (op) {
            case (1): {
                real_add(x1, y1, x2, y2, 1);
                break;
            }
            case (2): {
                int res = real_query(x1, y1, x2, y2);
                if (res & 1)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
                break;
            }
        }
    }
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
