#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, l[100005], r[100005];
map<int, int> mp[400005];

void modify(int mL, int mR, int val, int i = 1, int L = 0, int R = N)
{
    if (mL > mR)
        return;
    if (mL <= L && R <= mR)
        mp[i][val]++;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify(mL, mR, val, i << 1, L, mid);
        modify(mL, mR, val, i << 1 | 1, mid + 1, R);
    }
}

void build(int i = 1, int L = 0, int R = N)
{
    mp[i][N] = 1;
    int cur = mp[i].size();
    for (auto &[key, val] : mp[i])
        val = --cur;
    if (L != R)
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
    }
}

int query(int pos, int val, int i = 1, int L = 0, int R = N)
{
    int ans = mp[i].lower_bound(val)->S;
    if (L != R)
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            ans += query(pos, val, i << 1, L, mid);
        else
            ans += query(pos, val, i << 1 | 1, mid + 1, R);
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    string s;
    getline(cin, s);
    for (int i = 1; i <= N; i++)
    {
        stringstream ss;
        getline(cin, s);
        ss << s;
        char c;
        int a;
        while (ss >> c >> a)
            if (c == '+')
                l[a] = i;
            else
                r[a] = i - 1;
    }
    for (int i = 0; i < N; i++)
        modify(l[i], r[i], i);

    build();

    int x = 0;
    for (int i = 1; i <= N; i++)
    {
        int d;
        cin >> d;
        x = (x + query(d, x)) % N;
    }
    cout << x << '\n';
}
