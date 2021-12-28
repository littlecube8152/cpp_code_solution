#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int arr[200005], n, q, c, size;
struct Block
{
    int l, mid, r;
};
unordered_map<int, Block> block[450];

inline void cal_block(int i, int j)
{

    int l = 0, mid = 0, tmp = 0, r = 0;
    for (int k = 0; k < size && i * size + k < n && arr[i * size + k] != j; k++)
        l++;
    for (int k = 0; k < size && i * size + k < n; k++)
        if (arr[i * size + k] != j)
            tmp++;
        else
            mid = max(mid, tmp), tmp = 0;
    mid = max(mid, tmp);
    for (int k = min(n - (i * size) - 1, size - 1); k >= 0 && arr[i * size + k] != j; k--)
        r++;

    if (l == size)
        block[i].erase(j);
    else
        block[i][j] = Block{l, mid, r};
}

signed main()
{
    fast;
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    size = ceil(sqrt(3.8 * n));
    for (int i = 0; i < ((n + size - 1) / size); i++)
        for (int j = 0; j <= size && i * size + j < n; j++)
            if (block[i].find(arr[i * size + j]) == block[i].end())
                cal_block(i, arr[i * size + j]);

    for (int i = 1; i <= q; i++)
    {
        int x, a, b, c;
        cin >> x;
        if (x == 0)
        {
            cin >> a >> b;
            int p = arr[a];
            arr[a] = b;
            cal_block(a / size, p);
            cal_block(a / size, arr[a]);
        }
        else
        {
            cin >> a >> b >> c;
            int j = a, tmp = 0, val = 0;
            for (; j % size && j < b; j++)
                if (arr[j] != c)
                    tmp++;
                else
                    val = max(tmp, val), tmp = 0;
            for (; j < b - size; j += size)
            {
                auto iter = block[j / size].find(c);
                if (iter == block[j / size].end())
                    tmp += size;
                else
                {
                    val = max({tmp + iter->second.l, iter->second.mid, val});
                    tmp = iter->second.r;
                }
            }
            for (; j < b; j++)
                if (arr[j] != c)
                    tmp++;
                else
                    val = max(tmp, val), tmp = 0;
            val = max(tmp, val);
            cout << val << '\n';
        }
    }
}