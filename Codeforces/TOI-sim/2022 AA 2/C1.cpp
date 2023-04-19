#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, arr[50], L, R;
vector<ll> v1, v2;

void brute(int cur, int target, ll sum, vector<ll> &v)
{
    if (cur > target)
        v.emplace_back(sum);
    else
    {
        brute(cur + 1, target, sum, v);
        brute(cur + 1, target, sum + arr[cur], v);
    }
}

ll bs(ll left, ll right)
{
    if (left == right)
        return left;
    ll mid = (left + right + 1) / 2, cnt = 0;
    int last = v1.size() - 1;
    for (ll i : v2)
    {
        while (last >= 0 && i + v1[last] < mid)
            last--;
        cnt += last + 1;
    }
    //cout << mid << " " << cnt << '\n';
    if (cnt >= L)
        return bs(mid, right);
    else
        return bs(left, mid - 1);
}

signed main()
{

    cin >> N >> L >> R;
    assert(L == R);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    brute(1, N / 2, 0, v1);
    brute(N / 2 + 1, N, 0, v2);
    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());
    cout << bs(0, 1e11) << '\n';
}
/*
3 4 4
2 1 3
*/