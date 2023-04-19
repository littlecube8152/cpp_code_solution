#pragma GCC optimize("Ofast,unroll-loops")
#include "paint.h"
#ifndef EVAL
#include "grader.cpp"
#endif
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

vector<int> acc[100000];
vector<int> match[50000];
int minimumInstructions(
    int N, int M, int K, vector<int> C, vector<int> A, vector<vector<int>> B)
{
  for (int i = 0; i < M; i++)
    for (int j : B[i])
      acc[j].emplace_back(i);
  for (int i = 0; i < N; i++)
    for (int j : acc[C[i]])
      match[((j - i) % M + M) % M].emplace_back(i);

  vector<int> cover(N, 0), dp(N, 0);
  for (int x = 0; x < M; x++)
  {
    for (int l = 0; l + M - 1 < match[x].size(); l++)
      if (match[x][l] + M - 1 == match[x][l + M - 1])
      {
        //cerr << x << ' ' << match[x][l] << '\n';
        cover[match[x][l]] = 1;
      }
  }
  for (int i = 0; i < N; i++)
    dp[i] = (cover[i] ? i : (i ? dp[i - 1] : -1e9));

  int cur = 0, ans = 0;
  while (cur < N)
  {
    if (dp[cur] + M <= cur)
      break;
    cur = max(cur, dp[cur] + M), ans++;
  }
  return (cur < N ? -1 : ans);
}
