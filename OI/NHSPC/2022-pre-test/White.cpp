#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

vector<pii> v;
int idx = 0, vdx = 1;

vector<pii> White(int len, string str)
{
    v.clear();
    idx = 0;
    vdx = 1;
    str = "0" + str + "1";
    vector<int> st = {1};
    for(auto c : str)
        if(c == '0')
        {
            int nxt = ++vdx;
            v.emplace_back(pii(st.back(), vdx));
            st.emplace_back(vdx);
        }
        else 
            st.pop_back();
    return v;
}