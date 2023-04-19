#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c(char c)
{
	if(c == '@')
		return 0;
	if ('0' <= c && c <= '9')
		return c - '0' + 1;
	if('A' <= c && c <= 'Z')
		return c - 'A' + 11;
	return c - 'a' + 37;
}

struct node
{
	short cnt[64] = {};
	int child[64] = {};
	short total = 0;
};
node trie[4000005];

int N, idx = 1, T;
ll ans = 0;

void go(string &s, int i, int tidx)
{
	//cout << "go " << s << " " << i << " " << tidx << "\n";	
	if(i + 1 < s.size())
	{
		ans += trie[tidx].total + trie[tidx].cnt[c(s[i + 1])];
		trie[tidx].cnt[c(s[i + 1])]++;
		trie[tidx].total++;

		if(trie[tidx].child[c(s[i + 1])] == 0)
			trie[tidx].child[c(s[i + 1])] = ++idx;
		go(s, i + 1, trie[tidx].child[c(s[i + 1])]);
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 0;
	while(cin >> N) 
	{
		if(N == 0)
			break;
		t++;
		idx = 1, ans = 0;
		for(int i = 1; i <= N; i++)
		{
			string s;
			cin >> s;
			s = " " + s + "@";
			go(s, 0, 1);
		}
		cout << "Case " << t << ": " << ans << '\n';
		for(int i = 1; i <= idx; i++)
		{
			trie[i].total = 0;
			for(int j = 0; j < 100; j++)
				trie[i].cnt[j] = trie[i].child[j] = 0;
		}			
	}
}
