/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};  

ll A, B, M, k = 0, ans[100005], vertexcoloredge[2005][2005], vertexcolorvertex[2005][1005];

void free(int vertex, int colorfrom, int colorto)
{
    //cout << vertex << " " << colorfrom << "->" << colorto << '\n';
    int other = vertexcolorvertex[vertex][colorfrom];
    if (vertexcoloredge[vertex][colorfrom] == 0)
    {
        ans[vertexcoloredge[vertex][colorfrom]] = colorto;
        swap(vertexcoloredge[vertex][colorto], vertexcoloredge[vertex][colorfrom]);
        //swap(vertexcolorvertex[vertexcolorvertex[vertex][colorto]][colorto], vertexcolorvertex[vertexcolorvertex[vertex][colorfrom]][colorfrom]);
        swap(vertexcolorvertex[vertex][colorto], vertexcolorvertex[vertex][colorfrom]);
        return;
    }
    int edgeid = vertexcoloredge[vertex][colorfrom];
    free(other, colorto, colorfrom);
    ans[edgeid] = colorto;
    swap(vertexcoloredge[vertex][colorto], vertexcoloredge[vertex][colorfrom]);
    swap(vertexcolorvertex[vertex][colorto], vertexcolorvertex[vertex][colorfrom]);
    
}

signed main()
{
    //fast;
    cin >> A >> B >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y, xc = 1, yc = 1;
        cin >> x >> y;
        y += 1000;
        while (vertexcoloredge[x][xc] != 0)
            xc++;
        while (vertexcoloredge[y][yc] != 0)
            yc++;

        if (xc != yc)
            free(y, xc, yc);

        vertexcolorvertex[x][xc] = y;
        vertexcolorvertex[y][xc] = x;
        ans[i] = xc;
        vertexcoloredge[x][xc] = i;
        vertexcoloredge[y][xc] = i;

        //for (int i = 1; i <= M; i++)
        //    cout << ans[i] << " ";
        //cout << '\n';
    }
    for (int i = 1; i <= M; i++)
        k = max(k, ans[i]);
    cout << k << '\n';
    for (int i = 1; i <= M; i++)
        cout << ans[i] << " ";
}
