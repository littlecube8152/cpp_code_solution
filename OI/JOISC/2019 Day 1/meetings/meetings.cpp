#include "meetings.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void bridge(int u, int v)
{
  Bridge(min(u, v), max(u, v));
}

void solve(vector<int> v)
{
  if (v.size() == 1)
    return;
  if (v.size() == 2)
  {
    bridge(v[0], v[1]);
    return;
  }

  shuffle(v.begin(), v.end(), rd);

  // cerr << "solve " << v[0] << ' ' << v[1] << '\n';
  // for(auto i : v)
  //   cout << i << ' ';
  // cout << '\n';

  vector<pii> res = {pii(v[0], v[0]), pii(v[1], v[1])};
  vector<int> line;
  for (int i = 2; i < v.size(); i++)
  {
    res.emplace_back(pii(Query(v[0], v[1], v[i]), v[i]));
    if (res.back().F == res.back().S)
      line.emplace_back(v[i]);
  }
  sort(res.begin(), res.end());
  int last = res.front().F;
  vector<int> child;
  for (auto [i, j] : res)
  {
    if (i != last)
    {
      solve(child);
      child.clear();
      last = i;
    }
    child.emplace_back(j);
  }
  solve(child);
  sort(line.begin(), line.end(), [&](int i, int j)
       { if(i == j) return false;
        return Query(v[0], i, j) == i; });

  line.insert(line.begin(), v[0]);
  line.emplace_back(v[1]);
  for (int i = 1; i < line.size(); i++)
    bridge(line[i], line[i - 1]);
}

void Solve(int N)
{
  vector<int> node;
  for (int i = 0; i < N; i++)
    node.emplace_back(i);
  solve(node);
}
