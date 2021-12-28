#include "hexagon.h"
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

struct vec
{
  long long x, y;
  vec(pair<long long, long long> p) : x(p.first), y(p.second){};
  long long operator*(vec V2)
  {
    return x * V2.y - y * V2.x;
  }
};

int draw_territory(int N, int A, int B,
                   std::vector<int> D, std::vector<int> L)
{
  vector<pair<long long, long long>> v;
  v.push_back(make_pair(0, 0));
  for (int i = 0; i < N; i++)
  {
    if (D[i] == 1)
      v.push_back(make_pair(v.back().first + 2LL * L[i], v.back().second));
    if (D[i] == 4)
      v.push_back(make_pair(v.back().first - 2LL * L[i], v.back().second));
    if (D[i] == 2)
      v.push_back(make_pair(v.back().first + 1LL * L[i], v.back().second + 1LL * L[i]));
    if (D[i] == 5)
      v.push_back(make_pair(v.back().first - 1LL * L[i], v.back().second - 1LL * L[i]));
    if (D[i] == 3)
      v.push_back(make_pair(v.back().first + 1LL * L[i], v.back().second - 1LL * L[i]));
    if (D[i] == 6)
      v.push_back(make_pair(v.back().first - 1LL * L[i], v.back().second + 1LL * L[i]));
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
    ans = (ans + vec(v[i]) * vec(v[i + 1]) * 3LL) % MOD;
  /*
  for (int i = 0; i < N; i++)
  {
    if (abs(D[(i + N - 1) % N] - D[i]) == 1)
      ans = (ans + 5) % MOD;
    if (abs(D[(i + N - 1) % N] - D[i]) == 2)
      ans = (ans + 4) % MOD;
    if (abs(D[(i + N - 1) % N] - D[i]) == 3)
      ans = (ans + 3) % MOD;
  }
  for (int i : L)
    ans = (ans + (i - 1) * 3);*/

  ans = ((ans * 83333334) % MOD) * A % MOD;
  return ans;
}
