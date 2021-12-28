#include <bits/stdc++.h>
using namespace std;
vector<int> a = {2, 3, 2}, n = {3, 5, 7};

void exgcd(int a, int b, int c, int &x, int &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        exgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}

pair<int, int> solve(int L, int R)
{
    if (L == R)
        return make_pair(a[L], n[L]);
    if (L + 1 == R)
    {
        int p, q, N = n[L] * n[R];
        exgcd(n[L], n[R], a[R] - a[L], p, q);
        return make_pair(((p * n[L] + a[L]) % N + N) % N, N);
    }
    pair<int, int> left = solve(L, (L + R) / 2), right = solve((L + R) / 2 + 1, R);
    int p, q, N = left.second * right.second;
    exgcd(left.second, right.second, right.first - left.first, p, q);
    return make_pair(((p * left.second + left.first) % N + N) % N, N);
}

signed main()
{
    cout << solve(0, 2).first;
}