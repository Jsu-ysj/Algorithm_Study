#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
unordered_set<int> cs;
// map<vector<int>, bool> st;
unordered_set<long long> st;
int C[3];

vector<int> pour(vector<int> c, int i, int j) {
    int s = min(c[i], C[j] - c[j]);
    c[i] -= s;
    c[j] += s;
    return c;
}

long long get(vector<int> a) { return a[0] * 10000 * 10000 + a[1] * 10000 + a[2]; }

void dfs(vector<int> a) {
    st.insert(get(a));
    cs.insert(a[2]);
    vector<int> c = a;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i == j) continue;
            c = pour(a, i, j);
            if (!st.count(get(c))) dfs(c);
        }
    }
}

void solve() {
    while (cin >> C[0] >> C[1] >> C[2] && C[2] + C[1] + C[0] >= 0) {
        st.clear();
        cs.clear();
        vector<int> a = {0, 0, C[2]};
        dfs(a);
        cout << cs.size() << endl;
    }
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
