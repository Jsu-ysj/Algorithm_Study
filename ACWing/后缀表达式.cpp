#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
string op[25];
int ls[25], rs[25];
std::map<int, int> in;

string dfs(int u) {
    if (ls[u] == -1 && rs[u] == -1) { return "(" + op[u] + ")"; }
    if (ls[u] == -1 && ~rs[u]) { return "(" + op[u] + dfs(rs[u]) + ")"; }
    return "(" + dfs(ls[u]) + dfs(rs[u]) + op[u] + ")";
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> ls[i] >> rs[i];
        if (ls) in[ls[i]]++;
        if (rs) in[rs[i]]++;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            root = i;
            break;
        }
    }
    cout << dfs(root) << endl;
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
