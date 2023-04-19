#include "doll.h"
#include <bits/stdc++.h>
// #ifndef EVAL
// #include "grader.cpp"
// #endif
using namespace std;

namespace
{
  int K = 0;
  vector<int> X, Y, A, state;
  int construct(int N, int sz)
  {
    if (sz == 1)
      return 0;
    else
    {
      int l = -1, r = -1, id = ++K;
      X.emplace_back(0);
      Y.emplace_back(0);
      if (N > sz / 2)
      {
        r = construct(sz / 2, sz / 2);
        l = construct(N - sz / 2, sz / 2);
      }
      else
        r = construct(N, sz / 2);
      X[id - 1] = l;
      Y[id - 1] = r;
      return -id;
    }
  }
  void dfs(int cur, int idx = 0)
  {
    if (cur == 0)
      return;
    if (cur > 0)
      dfs(-1, idx);
    if (cur < 0)
    {
      state[-cur - 1] ^= 1;
      int nxt = state[-cur - 1] ^ 1;
      if((nxt ? Y : X)[-cur - 1] == 0)
        (nxt ? Y : X)[-cur - 1] = A[idx++];
      dfs((nxt ? Y : X)[-cur - 1], idx);
    }
  }
};

void create_circuit(int M, vector<int> A)
{
  vector<int> C(M + 1, -1);

  A.emplace_back(0);
  int N = A.size(), lg = __lg(N - 1) + 1;
  ::A = A;
  construct(N, 1 << lg);
  state.resize(X.size());
  dfs(-1);

  answer(C, X, Y);
}
