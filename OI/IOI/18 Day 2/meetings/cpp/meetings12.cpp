#include "meetings.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

namespace
{
  int N, Q;
  pll mx[5005][5005];
  vector<int> H;
};

ll query(int L, int R)
{
  if (R < L)
    return 1e18;
  if (L == R)
    return H[L];
  else
  {
    auto [h, mid] = mx[L][R];
    return min(query(L, mid - 1) + (R - mid + 1) * h, query(mid + 1, R) + (mid - L + 1) * h);
  }
}

vector<ll> minimum_costs(vector<int> H, vector<int> L, vector<int> R)
{
  N = H.size(), Q = L.size();
  ::H = H;
  vector<ll> C(Q);
  for (int i = 0; i < N; i++)
    mx[i][i] = pii(H[i], i);
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      mx[i][j] = max(mx[i][j - 1], mx[j][j]);
  for (int i = 0; i < Q; i++)
    C[i] = query(L[i], R[i]);
  return C;
}
