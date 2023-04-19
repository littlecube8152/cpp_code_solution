#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
int s[1000015],n;
signed main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        int l,r; cin>>l>>r;
        s[l]++; s[r]--;
    }
    for (int i=1;i<=1000005;i++)
        s[i]=s[i-1]+s[i];
    int ans=0;
    for (int i=1;i<=1000005;i++){
        ans=(ans+s[i]*(s[i]-1)/2);
    }
    cout<<ans<<'\n';
}