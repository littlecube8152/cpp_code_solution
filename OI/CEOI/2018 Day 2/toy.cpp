#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Merge(vector<int> &big, vector<int> small)
{
    vector<int> ans;
    int idx = 0, jdx = 0;
    for (; idx < big.size() || jdx < small.size();)
    {
        if (idx >= big.size())
            ans.emplace_back(small[jdx++]);
        else if (jdx >= small.size())
            ans.emplace_back(big[idx++]);
        else if (small[jdx] < big[idx])
            ans.emplace_back(small[jdx++]);
        else
            ans.emplace_back(big[idx++]);
    }
    ans.swap(big);
}

vector<int> solve(int N, int K)
{
    vector<int> ans;
    if (N <= K)
        ans = {N - 1};

    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
        {
            vector<int> v, w;
            if (N / i <= K)
            {
                v = solve(i, N / i);
                for (int &j : v)
                    j += (N / i - 1);

                Merge(ans, v);
                ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
            }
            if (i <= K)
            {
                w = solve(N / i, i);
                for (int &j : w)
                    j += (i - 1);

                Merge(ans, w);
                ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
            }
        }
    return ans;
}

signed main()
{
    int N;
    cin >> N;
    vector<int> ans = solve(N, N);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}
