#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n;

int inv(vector<int> u, vector<int> v)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (v[i] == u[j])
            {
                u[j] = 0;
                v[i] = j;
                break;
            }
    for (int i = 0; i < 4; i++)
        for (int j = i; j < 4; j++)
            ans += (v[i] > v[j]);
    return ans;
}

int eval(vector<int> v)
{
    for (auto i : v)
        if(i == 1e6)
            return 1e6;
    vector<int> st;
    st.emplace_back(v[0]);
    for (int i = 1; i + 1 < v.size(); i += 2)
    {
        if(v[i] == 3)
        {
            int j = st.back();
            st.pop_back();
            st.emplace_back(j * v[i + 1]);
        }
        else if(v[i] == 4)
        {
            int j = st.back();
            st.pop_back();
            if(v[i + 1] == 0 || j % v[i + 1])
                return 1e6;
            st.emplace_back(j / v[i + 1]);
        }
        else if(v[i] == 1)
            st.emplace_back(v[i + 1]);
        else if(v[i] == 2)
            st.emplace_back(-v[i + 1]);
    }
    int sum = 0;
    for (auto i : st)
        sum += i;
    return sum;
}

signed
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // enumerate inversion
    // paratheses: (ab)cd, a(bc)d, ab(cd), (ab)(cd), (abc)d, a(bcd)
    vector<int> v(4), u;
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    u = v;
    int ans = 1e9;
    sort(u.begin(), u.end());
    do
    {
        int iv = inv(u, v)* 2;
        for (int a = 1; a <= 4; a++)
            for (int b = 1; b <= 4; b++)
                for (int c = 1; c <= 4; c++)
                {
                    if(eval({u[0], a, u[1], b, u[2], c, u[3]}) == 24)
                        ans = min(ans, iv);
                    if(eval({eval({u[0], a, u[1]}), b, u[2], c, u[3]}) == 24)
                        ans = min(ans, iv + 1);
                    if(eval({u[0], a, eval({u[1], b, u[2]}), c, u[3]}) == 24)
                        ans = min(ans, iv + 1);
                    if(eval({u[0], a, u[1], b, eval({u[2], c, u[3]})}) == 24)
                        ans = min(ans, iv + 1);
                    if(eval({eval({u[0], a, u[1], b, u[2]}), c, u[3]}) == 24)
                        ans = min(ans, iv + 1);
                    if(eval({u[0], a, eval({u[1], b, u[2], c, u[3]})}) == 24)
                        ans = min(ans, iv + 1);
                    if(eval({eval({u[0], a, u[1]}), b, eval({u[2], c, u[3]})}) == 24)
                        ans = min(ans, iv + 2);
                }
    } while (next_permutation(u.begin(), u.end()));
    if(ans >= 1e9)
        cout << "impossible\n";
    else
        cout << ans << '\n';
}