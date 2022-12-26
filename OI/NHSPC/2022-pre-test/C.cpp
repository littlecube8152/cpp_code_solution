#include "Egg.h"
#define ll long long

ll height_limit(ll M)
{
    ll L = 1, R = M;
    while(L < R)
    {
        ll mid = (L + R + 1) / 2;
        if(is_broken(mid))
            R = mid - 1;
        else 
            L = mid;
    }
    return L;
}