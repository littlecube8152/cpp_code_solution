#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct fraction
{
    // a / b
    ll a, b;

    fraction(ll _a, ll _b) : a(_a), b(_b){};

    bool operator<(const fraction &f)
    {
        ll i1 = this->a / this->b, i2 = f.a / f.b;
        if(i1 != i2)
            return i1 < i2;
        else
        {
            ll d1 = this->a % this->b, d2 = f.a % f.b;
            if(d2 == 0)
                return false;
            if(d1 == 0)
                return true;
            return fraction(f.b, d2) < fraction(this->b, d1);
        }
    }
};

signed main()
{

}