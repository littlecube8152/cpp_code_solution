#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

bool query(long long K);

long long gfirst(long long N)
{
    if (N <= 3)
        return 1;
    return (N + 1) / 2 + 1 - gfirst((N + 1) / 2);
}

long long solve(long long N, long long extend = 0, long long side = 1, long long current = 1, bool start = 1)
{
    if (start)
        current = gfirst(N);

    if (N == 1)
        return 1;
    else if (N == 2)
    {
        if (start)
            query(current);
        if (query(current + side * 1 + side * extend))
            return 1;
        else
            return 2;
    }
    else if (N == 3)
    {
        if (start)
            query(current);
        if (query(current + side * 2 + side * extend))
        {
            if (query(current + side * 1))
                return 1;
            else
                return 2;
        }
        else
            return 3;
    }

    bool res;
    if (side == 1)
    {
        if (start)
            query(current);
        current = current + N / 2 + extend;
        res = query(current);
    }
    else
    {
        if (start)
            query(current);
        current = current - N / 2 - extend;
        res = query(current);
    }
    if (res)
        return solve(N / 2, extend, -side, current, false);
    else
        return N / 2 + solve(N - N / 2, extend + N / 2, -side, current, false);
}

long long N, C, last = 0, qcount = 0;
map<long long, bool> mp;
vector<long long> v;

bool query(long long K)
{
    v.emplace_back(K);
    if (qcount >= 64)
        cout << "Wrong Answer: Query too much\n";
    qcount++;
    if (mp[K])
        cout << "Wrong Answer: Query Same\n";
    if (K <= 0 || K > N)
        cout << "Wrong Answer: Query not in Range\n";
    mp[K] = 1;
    long long dis = abs(K - last);
    last = K;
    if (dis >= C)
        return 1;
    return 0;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        v.clear();
        mp.clear();
        qcount = 0;
        cin >> N >> C;
        long long ans = solve(N);
        if (ans != C)
            cout << "Wrong Answer: Output != Answer, Output: " << ans << '\n';
        else
            cout << "Accepted\n";
        for (long long i : v)
            cout << i << " ";
        cout << '\n';
    }
}


/*
1 : 1-3
2 : 4
3
*/