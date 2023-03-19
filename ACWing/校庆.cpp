#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
// 默认每年365, 每月30
struct node {
    string str;
    int age;
};
bool cmp(node x1, node x2) { return x1.age < x2.age; }

void solve() {
    int n, m;
    cin >> n;
    std::vector<node> a(n);
    std::map<string, int> vis;
    for (int i = 0; i < n; i++) {
        cin >> a[i].str;
        vis[a[i].str]++;
    }
    cin >> m;
    std::vector<node> b(m);
    std::vector<node> c;
    for (int i = 0; i < m; i++) {
        cin >> b[i].str;
        int year = 0;
        int yue  = 0;
        int ri   = 0;
        for (int j = 6; j <= 9; j++) {
            year += (b[i].str[j] - '0');
            year *= 10;
        }
        for (int j = 10; j <= 11; j++) {
            yue += (b[i].str[j] - '0');
            yue *= 10;
        }
        for (int j = 12; j <= 13; j++) {
            ri += (b[i].str[j] - '0');
            ri *= 10;
        }
        b[i].age = year / 10 * 365 + yue / 10 * 30 + ri / 10;
        // cout << year << " " << yue << " " << ri << endl;
        if (vis[b[i].str]) { c.push_back(b[i]); }
    }
    cout << c.size() << endl;
    if (c.size()) {
        sort(c.begin(), c.end(), cmp);
        cout << c[0].str << endl;
    } else {
        sort(b.begin(), b.end(), cmp);
        cout << b[0].str << endl;
    }
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
