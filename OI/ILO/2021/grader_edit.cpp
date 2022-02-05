#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> train(int n);

bool check(vector<pair<int, int>> ans, vector<pair<int, int>> res)
{
  for (pair<int, int> &p : ans)
  {
    if (p.first > p.second)
    {
      swap(p.first, p.second);
    }
  }
  for (pair<int, int> &p : res)
  {
    if (p.first > p.second)
    {
      swap(p.first, p.second);
    }
  }
  sort(ans.begin(), ans.end());
  sort(res.begin(), res.end());
  return (ans == res);
}

int n;
int queries = 0;
vector<int> pr;

bool validate(vector<int> &s)
{
  vector<bool> seen(n + n + 1, false);
  for (int i : s)
  {
    if (i < 1 || i > n + n || seen[i])
      return false;
    seen[i] = true;
  }
  return true;
}
int distinct(vector<int> s)
{
  if (!validate(s))
  {
    cout << "You queried a wrong set\n";
    exit(0);
  }
  ++queries;
  int uni = 0;
  vector<bool> has(n + n + 1, false);
  for (int i : s)
  {
    if (!has[i])
    {
      ++uni;
      has[i] = has[pr[i]] = true;
    }
  }
  for(int i : s)
    cout << i << " ";
  cout << " = " << uni << '\n';
  return uni;
}
int main()
{
  cin >> n;
  pr.resize(n + n + 1);
  vector<pair<int, int>> ans(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> ans[i].first >> ans[i].second;
    pr[ans[i].first] = ans[i].second;
    pr[ans[i].second] = ans[i].first;
  }
  vector<pair<int, int>> res = train(n);
  for (auto p : res)
    cout << p.first << " " << p.second << '\n';
  if (check(ans, res))
  {
    cout << "Correct! "
         << "You made " << queries << " queries\n";
  }
  else
  {
    cout << "Wrong Answer\n";
  }
  return 0;
}
