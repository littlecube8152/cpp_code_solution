#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll rand64()
{
    return ((rand() % 2) * (((ll)rand()) << 45) + (rand() % 2) * (((ll)rand()) << 30) + (rand() % 2) * (((ll)rand()) << 15) + (rand() % 2) * ((ll)rand()));
}

ll g(ll x, ll c, ll a)
{
    return (x * x + c) % (10 * a);
}

ll gcd(ll a, ll b)
{
    if (a * b == 0)
        return max(abs(a), abs(b));
    return gcd(b, a % b);
}

vector<ll> spliting(ll a)
{
    vector<ll> r;
    vector<ll> k;

    ll c = rand64();
    k.emplace_back(rand64());
    for (ll i = 1; i <= (sqrt(a)); i++)
    {
        k.emplace_back(g(k[i - 1], c, a));
        ll d = gcd(abs(k[i] - k[i / 2]), a);
        if (d == a)
            c = rand64();
        else if (d > 1)
        {
            r = spliting(a / d);
            vector<ll> AD = spliting(d);
            r.insert(r.end(), AD.begin(), AD.end());
            break;
        }
        //cout << (abs(k[i] - k[i / 2])% (ll)(sqrt(a)) + (ll)(sqrt(a))) << "\n";
    }
    if (r.empty())
        r.emplace_back(a);
    return r;
}
signed main()
{
    srand(time(NULL));
    ll a;
    cin >> a;
    vector<ll> r = spliting(a);
    sort(r.begin(), r.end());

    cout << r.size() << '\n';
    for (ll i : r)
        cout << i << " ";
}