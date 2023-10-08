#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n;
string s;
vector<int> v;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i += 3)
	{
		string t = s.substr(i, 3);
		if (i == 0)
		{
			if (t == "000" || t == "111")
				v.emplace_back(1);
		}
		else 
		{
			if (s[i - 1] == '1')
				for (auto &c : t)
					c ^= 1;
			if (t == "000")
				v.emplace_back(i + 1);
			else if (t == "001")
				v.emplace_back(i + 2), s[i + 2] ^= 1;
			else if (t == "011")
				v.emplace_back(i + 1);
			else if (t == "111")
				v.emplace_back(i + 2), s[i + 2] ^= 1;
		}
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " \n"[i + 1 == v.size()];
}
