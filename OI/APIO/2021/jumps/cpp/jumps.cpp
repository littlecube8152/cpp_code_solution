#include "jumps.h"
#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005] = {0};
vector<int> e[2005];
void init(int N, std::vector<int> H)
{
  vector<int> st;
  for (int i = 0; i < N; i++)
  {
    while (!st.empty() && H[i] > H[st.back()])
      st.pop_back();
    if (!st.empty())
      e[i].push_back(st.back());
    st.push_back(i);
  }
  st.clear();
  for (int i = N - 1; i >= 0; i--)
  {
    while (!st.empty() && H[i] > H[st.back()])
      st.pop_back();
    if (!st.empty())
      e[i].push_back(st.back());
    st.push_back(i);
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dp[i][j] = 1000000;
  for (int i = 0; i < N; i++)
  {
    bool vis[2005] = {0};
    vis[i] = 1;
    dp[i][i] = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty())
    {
      for(int j : e[q.front()])
        if(!vis[j])
        {
          vis[j] = 1;
          dp[i][j] = dp[i][q.front()] + 1;
          q.push(j);
        }
      q.pop();
    }
  }
}

int minimum_jumps(int A, int B, int C, int D)
{
  int ans = 1000000;
  for (int i = A; i <= B; i++)
    for (int j = C; j <= D; j++)
      ans = min(ans, dp[i][j]);

  return (ans >= 1000000 ? -1 : ans);
  return 0;
}
