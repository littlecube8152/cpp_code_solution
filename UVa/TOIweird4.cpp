#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, dp[105][105], T;
string s, t;
signed main()
{

	while(getline(cin, s))
	{
		if(!getline(cin, t))
			break;
		for(int i = 1; i <= s.size(); i++)
			for(int j = 1; j <= t.size(); j++)
				dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1])});
		cout << "Case #" << ++T << ": you can visit at most " << dp[s.size()][t.size()] << " cities.\n";
	}
}
