#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, s[100001], result = 1000000000, min_pos, front = 0, back = 0;
vector<int> positive, negative;

ll four_max(ll a, ll b, ll c, ll d)
{
    return max(max(a, b), max(c, d));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll pos, facing;
        cin >> pos >> facing;
        s[i] = pos;
        if (facing == 0)
        {
            positive.push_back(pos);
        }
        else
        {
            negative.push_back(pos);
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll lower = 0, upper = 0, a = 0, b = 0;
        if (!negative.empty())
        {
            b = negative.back() - s[i];
            if (!(s[i] <= negative.front()))
                lower = n - abs(s[i] - *(lower_bound(negative.begin(), negative.end(), s[i]) - 1));
        }
        if (!positive.empty())
        {
            a = s[i] - positive.front();
            if (!(s[i] >= positive.back()))
                upper = n - abs(*upper_bound(positive.begin(), positive.end(), s[i]) - s[i]);
        }
        ll distance = four_max(a, lower, b, upper);
        if (distance < result)
        {
            min_pos = s[i];
            result = distance;
        }
    }
    cout << min_pos << " " << result << '\n';
}