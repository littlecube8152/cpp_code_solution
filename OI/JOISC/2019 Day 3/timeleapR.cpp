#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int N, Q;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ofstream cout("test.in");
    cin >> N >> Q;
    cout << N << ' ' << Q << '\n';
    for (int i = 1; i < N; i++)
    {
        int a = rd() % 10, b = rd() % 10;
        while(a == b)
            a = rd() % 10, b = rd() % 10;
        if(a > b)
            swap(a, b);
        cout << a << ' ' << b << '\n';
    }
    for (int i = 1; i < Q; i++)
    {
        int a = rd() % 10, b = rd() % 10, c = rd() % N, d = rd() % N;
        cout << 2 << ' ' << c + 1 << ' ' << a << ' ' << d + 1 << ' ' << b << '\n';
    }
}