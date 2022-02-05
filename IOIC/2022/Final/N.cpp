#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

bool solve()
{
    int N, M, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> N >> M >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (pii{x1, y1} > pii{x2, y2})
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (pii{x3, y3} > pii{x4, y4})
    {
        swap(x3, x4);
        swap(y3, y4);
    }
    if (M == 1 && x1 < x3 && x3 < x2 && x2 < x4)
        return 0;
    if (M == 1 && x3 < x1 && x1 < x4 && x4 < x2)
        return 0;
    if (M == 1 && x1 < x3 && x3 < x4 && x4 < x2)
        return 0;
    if (M == 1 && x3 < x1 && x1 < x2 && x2 < x4)
        return 0;
    if (N == 1 && y3 < y1 && y1 < y4 && y4 < y2)
        return 0;
    if (N == 1 && y1 < y3 && y3 < y2 && y2 < y4)
        return 0;
    if (N == 1 && y3 < y1 && y1 < y2 && y2 < y4)
        return 0;
    if (N == 1 && y1 < y3 && y3 < y4 && y4 < y2)
        return 0;
    if (x2 == x1 + 1 && y2 == y1 + 1 && x3 == x1 && y3 == y1 + 1 && x4 == x1 + 1 && y4 == y1)
        return 0;
    if (x2 == x1 + 1 && y2 == y1 - 1 && x3 == x1 && y3 == y1 - 1 && x4 == x1 + 1 && y4 == y1)
        return 0;
    if (x3 == 1 && y3 == 1 && x1 == 1 && y1 == 2 && x2 == 2 && y2 == 1)
        return 0;
    if (x1 == 1 && y1 == 1 && x3 == 1 && y3 == 2 && x4 == 2 && y4 == 1)
        return 0;
    if (((x3 == N && y3 == 1) || (x4 == N && y4 == 1)) && x1 == N - 1 && y1 == 1 && x2 == N && y2 == 2)
        return 0;
    if (((x1 == N && y1 == 1) || (x2 == N && y2 == 1)) && x3 == N - 1 && y3 == 1 && x4 == N && y4 == 2)
        return 0;
    if (((x3 == 1 && y3 == M) || (x4 == 1 && y4 == M)) && x1 == 1 && y1 == M - 1 && x2 == 2 && y2 == M)
        return 0;
    if (((x1 == 1 && y1 == M) || (x2 == 1 && y2 == M)) && x3 == 1 && y3 == M - 1 && x4 == 2 && y4 == M)
        return 0;
    if (((x3 == N && y3 == M) || (x4 == N && y4 == M)) && x1 == N - 1 && y1 == M && x2 == N && y2 == M - 1)
        return 0;
    if (((x1 == N && y1 == M) || (x2 == N && y2 == M)) && x3 == N - 1 && y3 == M && x4 == N && y4 == M - 1)
        return 0;
    auto onedge = [&](int x, int y)
    { return x == 1 || x == N || y == 1 || y == M; };
    auto sgn = [](ll a, ll b, ll c, ll d)
    {
        ll res = a * d - b * c;
        if (res < 0)
            return -1;
        return res == 0 ? 0 : 1;
    };
    if (onedge(x1, y1) && onedge(x2, y2) && onedge(x3, y3) && onedge(x4, y4))
    {
        if (sgn(x1 - x3, y1 - y3, x4 - x3, y4 - y3) * sgn(x2 - x3, y2 - y3, x4 - x3, y4 - y3) == -1 &&
            sgn(x3 - x1, y3 - y1, x2 - x1, y2 - y1) * sgn(x4 - x1, y4 - y1, x2 - x1, y2 - y1) == -1)
            return 0;
        bool samex132 = (x1 == x3 && x3 == x2 && y1 < y3 && y3 < y2);
        bool samex142 = (x1 == x4 && x4 == x2 && y1 < y4 && y4 < y2);
        bool samex314 = (x3 == x1 && x1 == x4 && y3 < y1 && y1 < y4);
        bool samex324 = (x3 == x2 && x2 == x4 && y3 < y2 && y2 < y4);
        bool samey132 = (y1 == y3 && y3 == y2 && x1 < x3 && x3 < x2);
        bool samey142 = (y1 == y4 && y4 == y2 && x1 < x4 && x4 < x2);
        bool samey314 = (y3 == y1 && y1 == y4 && x3 < x1 && x1 < x4);
        bool samey324 = (y3 == y2 && y2 == y4 && x3 < x2 && x2 < x4);
        if (samex132 ^ samex142)
            return 0;
        if (samex314 ^ samex324)
            return 0;
        if (samey132 ^ samey142)
            return 0;
        if (samey314 ^ samey324)
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
}