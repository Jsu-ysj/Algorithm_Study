#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 1005;
int n, m;
int g[N][N];
bool vis[N];
int dist[N];
int qq[N];

bool dij() {
    for (int i = 1; i <= n; i++) {
        dist[i] = 0x3f3f3f3f;
        vis[i]  = 0;
    }
    dist[qq[1]] = 0;
    for (int i = 1; i <= n; i++) {
        int t = qq[i];
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < dist[t]) return false;
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++) { dist[j] = min(dist[j], dist[t] + g[t][j]); }
    }
    return true;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) { g[i][j] = 0x3f3f3f3f; }

    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        g[x][y] = g[y][x] = v;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        for (int i = 1; i <= n; i++) scanf("%d", &qq[i]);
        if (dij()) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}

signed main() {
    int T = 1;
    // OST;
    while (T--) { solve(); }
    return 0;
}
