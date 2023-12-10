#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

string s[1000006];
int N, occ[26];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> s[i];
		occ[s[i][0] - 'A']++;
	}
	bool flag = 0;
	for (int i = 1; i <= N; i++)
	{
		bool valid = 1;
		for (auto c : s[i])
			if (!occ[c - 'A'])
				valid = 0;
		if(valid)
			flag = 1;
	}
	puts(flag ? "Y" : "N");
}
