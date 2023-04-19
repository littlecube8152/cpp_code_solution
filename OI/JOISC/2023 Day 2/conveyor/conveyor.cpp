#include "conveyor.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int d[100005], pre[100005];
vector<pair<int, pii>> E[100005];
vector<int> tree[3];

void dfs(int u)
{
  //cerr << u << ' ' << d[u] << '\n';
  tree[d[u]].emplace_back(u);
  for (auto [v, i] : E[u])
    if (v != pre[u])
    {
      pre[v] = u;
      d[v] = (d[u] + 1) % 3;
      dfs(v);
    }
}

void Solve(int N, vector<int> A, vector<int> B)
{
  mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> ans(N - 1, -1);
  for (int i = 0; i < N - 1; i++)
  {
    E[A[i]].emplace_back(make_pair(B[i], pii(i, 0)));
    E[B[i]].emplace_back(make_pair(A[i], pii(i, 1)));
  }

  int t = 10;
  while (t--)
  {
    for (int i = 0; i < N; i++)
      pre[i] = -1;
    int root = rd() % N;
    d[root] = 0;
    tree[0].clear(), tree[1].clear(), tree[2].clear();
    dfs(root);
    for (int r = 0; r < 3; r++)
    {
      vector<int> inv(N - 1, 0), put(N, 0), on;
      for (auto u : tree[r])
      {
        for (auto [v, p] : E[u])
          if (ans[p.F] == p.S)
            inv[p.F] = 1;

        put[u] = 1;
      }
      on = Query(inv, put);
      for (auto u : tree[r])
      {
        if (on[u])
        {
          for (auto [v, p] : E[u])
            ans[p.F] = 1 ^ p.S ^ inv[p.F];
        }
        else
        {
          pii ispre = pii(-1, -1);
          pii notpre = pii(-1, -1);
          for (auto [v, p] : E[u])
            if (on[v])
            {
              if (v == pre[u])
                ispre = p;
              else
                notpre = p;
            }
          if (notpre.F != -1)
          {
            assert(inv[notpre.F] == 0);
            ans[notpre.F] = notpre.S ^ inv[notpre.F];
          }
          else
          {
            assert(inv[ispre.F] == 0);
            ans[ispre.F] = ispre.S ^ inv[ispre.F];
          }
        }
      }
    }
    // for (int i : ans)
    //   cerr << i << ' ';
    // cerr << '\n';
  }
  // for (int i : ans)
  //   cerr << i << ' ';
  // cerr << '\n';
  Answer(ans);
}
