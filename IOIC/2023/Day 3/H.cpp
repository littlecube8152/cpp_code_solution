#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, Q;
ll a[200005], ans, l[4000006], r[4000006], m[4000006];

void modify(string &s, int val, int i = 1)
{
    if (s.empty())
    {
        m[i] += val;
        return;
    }
    char c = s.back();
    s.pop_back();
    if (c == '0')
    {
        l[i] += val;
        modify(s, val, i << 1);
    }
    else
    {
        r[i] += val;
        modify(s, val, i << 1 | 1);
    }
}

int match(int rem = N, int i = 1, int dep = 0)
{
    int p = 2 * min(l[i], r[i]), mx = l[i] + r[i] - p;
    if (m[i] >= mx)
        p += (m[i] + mx) / 2 * 2;
    else
        p += m[i] * 2;
    if (p >= rem)
        return -rem * dep;
    if (l[i] >= r[i])
        return -p * dep + match(rem - p, i << 1, dep + 1);
    else
        return -p * dep + match(rem - p, i << 1 | 1, dep + 1);
}

string parse(int k)
{
    string s;
    while (k)
    {
        s.push_back((k & 1) ? '1' : '0');
        k >>= 1;
    }
    return s;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    N *= 2;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        string s = parse(a[i]);
        ans += s.size();
        modify(s, 1);
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int x, y;
        cin >> x >> y;
        string s = parse(a[x]);
        ans -= s.size();
        modify(s, -1);
        s = parse(y);
        ans += s.size();
        modify(s, 1);
        a[x] = y;
        cout << ans + match() << '\n';
    }
}