#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>


#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, dsu[10005], val[10005];
pll arr[10005];

int find(int k)
{
    return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    dsu[x] = y;
    val[y] = min(val[x], val[y]);
}

void solve()
{
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        cin >> arr[i].F >> arr[i].S;
    for (int i = 0; i <= 1e4; i++)
        dsu[i] = val[i] = i;
    sort(arr + 1, arr + 1 + N, greater<pll>());
    for (int i = 1; i <= N; i++)
    {
        ll d = arr[i].S;
        int rd = val[find(d)];
        if (rd > 0)
        {
            ans += arr[i].F;
            merge(find(rd), find(rd - 1));
        }
    }
    cout << ans << '\n';
}

int main()
{
    while (cin >> N)
        solve();
}
