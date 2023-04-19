#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
string s;

struct segtree
{
    int seg[75005];
    int inv[75005];
    void modify(int pos, int dir, int i = 1, int L = 1, int R = 2 * N)
    {
        if (L == R)
            seg[i] ^= pos, inv[i] ^= 1;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, dir, i << 1, L, mid);
            else
                modify(pos, dir, i << 1 | 1, mid + 1, R);
            if (inv[i << 1] * inv[i << 1 | 1] <= 0)
            {
                seg[i] = seg[i << 1 | 1] - seg[i << 1];
            }
            seg[i] = (inv[i << 1 | 1] ? -seg[i << 1] : seg[i << 1]) + seg[i << 1 | 1];
            inv[i] = inv[i << 1] ^ inv[i << 1 | 1];
        }
    }

    void reset()
    {
        for (int i = 1; i <= 8 * N; i++)
            seg[i] = inv[i] = 0;
    }
} seg;

struct dynamic_median
{
    deque<int> L, R;
    int mid = 0;
    int centerL = 0, centerR = 0;
    void insertL(int k)
    {
        L.push_front(k);
        seg.modify(centerL - k + N);
        if (mid)
        {
            R.push_front(mid);
            seg.modify(mid - centerR + N);
            mid = 0;
        }
        else
        {
            mid = L.back();
            L.pop_back();
            seg.modify(centerL - mid + N);
        }
    }

    void insertR(int k)
    {
        R.push_back(k);
        seg.modify(k - centerR + N);
        if (mid)
        {
            L.push_back(mid);
            seg.modify(centerL - mid + N);
            mid = 0;
        }
        else
        {
            mid = R.front();
            R.pop_front();
            seg.modify(mid - centerR + N);
        }
    }
    int calc()
    {
        return seg.seg[1] + (mid ? abs(mid - centerR) : 0);
    }
    void reset()
    {
        L.clear();
        R.clear();
        mid = 0;
    }
} dym;

ll ans;

signed main()
{
    cin >> s;
    N = s.size();
    s = " " + s;

    for (int i = 1; i <= N; i++)
    {
        seg.reset();
        dym.reset();
        dym.centerL = dym.centerR = i;
        if (s[i] == 'G')
            dym.insertL(i);
        int l = i - 1, r = i + 1;

        for (; 1 <= l && r <= N; l--, r++)
        {
            if (s[l] == 'G')
                dym.insertL(l);
            if (s[r] == 'G')
                dym.insertR(r);
            ans += dym.calc();
            cout << s.substr(l, r - l + 1) << ' ' << dym.calc() << '\n';
        }
    }

    for (int i = 1; i < N; i++)
    {
        seg.reset();
        dym.reset();
        dym.centerL = i, dym.centerR = i + 1;
        int l = i, r = i + 1;

        for (; 1 <= l && r <= N; l--, r++)
        {
            if (s[l] == 'G')
                dym.insertL(l);
            if (s[r] == 'G')
                dym.insertR(r);
            ans += (dym.mid ? -1 : dym.calc());
            cout << s.substr(l, r - l + 1) << ' ' << (dym.mid ? -1 : dym.calc()) << '\n';
        }
    }
    cout << ans << '\n';
}
