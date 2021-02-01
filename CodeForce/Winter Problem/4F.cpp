#include <iostream>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int search_left1(int l, int r, int n)
{
    if(l == r)
        return l;
    if (l + 1 == r)
    {
        int ans;
        cout << "? " << r << " " << 0 << " " << n << " " << n << endl;
        cin >> ans;
        if (ans == 2)
            return r;
        else
            return l;
    }
    int ans;
    cout << "? " << (l + r) / 2 << " " << 0 << " " << n << " " << n << endl;
    cin >> ans;
    if (ans == 2)
        return search_left1((l + r) / 2, r, n);
    else
        return search_left1(l, (l + r) / 2, n);
}

int search_left2(int l, int r, int n)
{
    if(l == r)
        return l;
    if (l + 1 == r)
    {
        int ans;
        cout << "? " << r << " " << 0 << " " << n << " " << n << endl;
        cin >> ans;
        if (ans == 2)
            return r;
        else
            return l;
    }
    int ans;
    cout << "? " << (l + r) / 2 << " " << 0 << " " << n << " " << n << endl;
    cin >> ans;
    if (ans >= 1)
        return search_left2((l + r) / 2, r, n);
    else
        return search_left2(l, (l + r) / 2, n);
}

int main()
{
    fast;
    int n, l1, l2;
    cin >> n;
    l1 = search_left1(0, n, n);
    cout << search_left2(l1, n, n);
}