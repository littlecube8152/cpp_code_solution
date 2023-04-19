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
  struct node
  {
    int L, R, sum, mid;
  } seg[400000];
  vector<int> H;
};

node merge(node n1, node n2)
{
  return node{max(n1.L, n1.sum + n2.L), max(n2.R, n2.sum + n1.R), n1.sum + n2.sum, max(max(n1.mid, n2.mid), n1.R + n2.L)};
}

void build(int i = 1, int L = 0, int R = N - 1)
{
  if (L == R)
  {
    int val = (H[L] == 1 ? 1 : -N);
    seg[i] = node{max(val, 0), max(val, 0), val, max(val, 0)};
  }
  else
  {
    int mid = (L + R) / 2;
    build(i << 1, L, mid);
    build(i << 1 | 1, mid + 1, R);
    seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }
}

node query(int qL, int qR, int i = 1, int L = 0, int R = N - 1)
{
  if (qL <= L && R <= qR)
    return seg[i];
  else if (R < qL || qR < L)
    return node{0, 0, 0, 0};
  else
  {
    int mid = (L + R) / 2;
    return merge(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
  }
}

vector<ll> minimum_costs(vector<int> H, vector<int> L, vector<int> R)
{
  N = H.size(), Q = L.size();
  ::H = H;
  vector<ll> C(Q);
  build();
  for (int i = 0; i < Q; i++)
  {
    //cerr << query(L[i], R[i]).L << ' ' << query(L[i], R[i]).R << ' ' << query(L[i], R[i]).mid << ' ' << query(L[i], R[i]).sum << '\n';
    C[i] = (R[i] - L[i] + 1) * 2 - query(L[i], R[i]).mid;
  }
  return C;
}
