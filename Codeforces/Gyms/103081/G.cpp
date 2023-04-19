#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, p[2000006], d[2000006], nxt[2000006], ans = 1e18, id = 0, in[2000006], pos[2000006], dp[2000006], vis[2000006], last[2000006], pre[2000006], val[2000006], idx;

int dfs(int u)
{
    vis[u] = 1;
    int v = nxt[u];
    if (!vis[v])
        return dfs(v);
    else
        return (vis[v] == 1 ? u : -u - 1);
}

void calc(int u)
{
    vis[u] = 2;
    pre[nxt[u]] = u;
    if (vis[nxt[u]] < 2)
        calc(nxt[u]);
    if (pos[nxt[u]] == K || u == last[nxt[u]])
    {
        last[u] = pre[last[nxt[u]]];
        pos[u] = pos[nxt[u]];
        dp[u] = dp[nxt[u]] + val[u] - val[last[nxt[u]]];
    }
    else
    {
        last[u] = last[nxt[u]];
        pos[u] = pos[nxt[u]] + 1;
        dp[u] = dp[nxt[u]] + val[u];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    idx = N;
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i < N; i++)
        if (!p[i])
            for (int j = i; j < N; j += i)
                p[j] = i;
    for (int i = 2; i < N; i++)
    {
        d[i] = 1;
        int j = i;
        while (j > 1)
        {
            int cur = p[j], cnt = 1;
            while (j % cur == 0)
                j /= cur, cnt++;
            d[i] *= cnt;
        }
    }
    for (int i = 0; i < N; i++)
    {
        val[i] = i;
        nxt[i] = (i + d[i]) % N;
        in[nxt[i]] = 1;
        if (i == nxt[i])
        {
            vis[i] = 2;
            dp[i] = i;
            pos[i] = 1;
            last[i] = i;
        }
    }
    for (int i = 0; i < N; i++)
        if (in[i] == 0)
        {
            int k = dfs(i), l = -(k + 1), tmp;
            if (k >= 0)
            {
                pos[k] = 1, dp[k] = k;
                int newnxt = idx + 1;
                for (int j = nxt[k]; j != k && pos[k] < K; j = nxt[j])
                {
                    val[++idx] = j;
                    nxt[idx] = idx + 1;
                    pre[idx + 1] = idx;
                    last[k] = idx;
                    pos[k]++;
                    dp[k] += j;
                }
                nxt[k] = newnxt;
                pre[newnxt] = k;
                vis[k] = 2;
            }
            else 
                tmp = pre[nxt[l]];
            calc(i);
            if(k < 0)
                pre[nxt[l]] = tmp;
        }
    for (int i = 0; i < N; i++)
    {
        if (pos[i] == K && dp[i] < ans)
            ans = dp[i], id = i;
    }
    if (ans >= 1e17)
        cout << -1 << '\n';
    else
    {
        for (int i = 1; i <= K; i++, id = nxt[id])
            cout << val[id] << " \n"[i == K];
    }
}
/*
0 156   1 167   2 1   3 0   4 2   5 165   6 0   7 5   8 0   9 7   10 6   11 0   12 8   13 11   14 10   15 13   16 0   17 0   18 14   19 17   20 0   21 16   22 0   23 0   24 18   25 23   26 22   27 0   28 25   29 0   30 26   31 29   32 24   33 31   34 28   35 0   36 0   37 33   38 30   39 35   40 0   41 0   42 38   43 41   44 0   45 36   46 0   47 0   48 40   49 47   50 46   51 45   52 49   53 0   54 0   55 53   56 50   57 0   58 52   59 55   60 0   61 57   62 54   63 61   64 56   65 0   66 62   67 0   68 0   69 67   70 0   71 64   72 60   73 69   74 68   75 73   76 0   77 0   78 70   79 0   80 0   81 79   82 76   83 0   84 72   85 83   86 82   87 0   88 0   89 85   90 80   91 87   92 0   93 0   94 0   95 91   96 88   97 93   98 94   99 97   100 0   101 0   102 90   103 101   104 98   105 103   106 0   107 0   108 96   109 107   110 106   111 109   112 104   113 105   114 0   115 111   116 0   117 0   118 110   119 115   120 108   121 0   122 116   123 117   124 121   125 0   126 122   127 123   128 0   129 125   130 124   131 0   132 0   133 131   134 0   135 0   136 128   137 133   138 134   139 137   140 0   141 139   142 0   143 135   144 132   145 141   146 142   147 143   148 0   149 145   150 146   151 149   152 140   153 147   154 148   155 0   156 0   157 0   158 0   159 157   160 152   161 0   162 158   163 159   164 0   165 161   166 0   167 0 
*/
