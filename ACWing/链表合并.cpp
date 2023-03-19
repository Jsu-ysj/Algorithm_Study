#include <bits/stdc++.h>
#define OST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
struct node {
    int val, next;
} a[N], b[N], ans[N];
int n, m;
int str_to_int(string s) {
    int res = 0;
    if (s == "-1") { return -1; }
    for (int i = 0; i < s.size(); i++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

int count(int headInt) {
    int num = 0;
    int now = headInt;
    while (now != -1) {
        // cout << now << endl;
        num++;
        now = a[now].next;
    }
    return num;
}

int jiao_huan(int headInt) {
    int now = headInt;
    while (a[now].next != -1) {
        // cout << a[now].next << endl;
        int next     = a[now].next;
        b[now].val   = a[now].val;
        b[next].val  = a[next].val;
        b[next].next = now;
        now          = next;
    }
    b[now].val      = a[now].val;
    b[headInt].next = -1;
    return now;
}

void he_bing(int head1Int, int head2Int) {
    int now1 = head1Int;
    int now2 = head2Int;
    // cout << now1 << " " << now2 << endl;
    while (now1 != -1 || now2 != -1) {
        if (now1 != -1) {
            ans[now1].val  = a[now1].val;
            ans[now1].next = a[now1].next;
            now1           = a[now1].next;
        }
        if (now1 != -1) {
            if (now2 != -1) {
                ans[now1].val  = a[now1].val;
                ans[now1].next = now2;
                now1           = a[now1].next;
            } else {
                ans[now1].val  = a[now1].val;
                ans[now1].next = a[now1].next;
                now1           = a[now1].next;
            }
        }
        if (now2 != -1) {
            ans[now2].val  = b[now2].val;
            ans[now2].next = now1;
            now2           = b[now2].next;
        }
    }
}

void shu_chu(int headInt) {
    int num = 0;
    int now = headInt;
    while (now != -1) {
        if (ans[now].next != -1) {
            printf("%05d %d %05d\n", now, ans[now].val, ans[now].next);
        } else {
            printf("%05d %d %d\n", now, ans[now].val, ans[now].next);
        }
        num++;
        now = ans[now].next;
    }
}
void solve() {
    string head1, head2;
    int n;
    cin >> head1 >> head2 >> n;
    int head1Int = str_to_int(head1);
    int head2Int = str_to_int(head2);
    for (int i = 0; i < n; i++) {
        // Address Data Next
        string Address, Data, Next;
        cin >> Address >> Data >> Next;
        int AddressInt = str_to_int(Address);
        int DataInt    = str_to_int(Data);
        int NextInt    = str_to_int(Next);
        // cout << AddressInt << " " << DataInt << " " << NextInt << endl;
        a[AddressInt] = {DataInt, NextInt};
    }
    int num1 = count(head1Int);
    int num2 = count(head2Int);
    // cout << num1 << " " << num2 << endl;
    if (num1 > num2) {
        head2Int = jiao_huan(head2Int);
        he_bing(head1Int, head2Int);
        shu_chu(head1Int);
    } else {
        head1Int = jiao_huan(head1Int);
        he_bing(head2Int, head1Int);
        shu_chu(head2Int);
    }
}

signed main() {
    int T = 1;

    while (T--) { solve(); }
    return 0;
}
