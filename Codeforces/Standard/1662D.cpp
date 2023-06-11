#include <bits/stdc++.h>

using namespace std;

string u, v;

pair<string, bool> simplify(string s)
{
	string t;
	bool B = 0;
	for(char c : s)
		if(c == 'B')
			B ^= 1;
		else
		{
			if(!t.empty() && t.back() == c)
				t.pop_back();
			else 
				t.push_back(c);
		}
	return make_pair(t, B);
}

bool dp[205][205];

void solve()
{
	int n, m;
	cin >> u >> v;
	
	cout << (simplify(u) == simplify(v) ? "YES\n" : "NO\n"); 
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
