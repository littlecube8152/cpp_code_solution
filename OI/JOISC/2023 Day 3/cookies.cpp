#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, A[15005], S[15005], sum, B[15005], range[15005], cover[15005], order[15005];
bitset<15005> dp[15005];
vector<int> all;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	dp[0][0] = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		sum += A[i];
		order[i] = i;
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> B[i];
	stable_sort(order + 1, order + 1 + N, [&](int i, int j){return A[i] > A[j];});
	stable_sort(A + 1, A + 1 + N, greater<>());

	for (int i = 1; i <= N; i++)
	{	
		for (int j = 1; j <= A[i]; j++)
			all.emplace_back(order[i]);
		for (int j = sum; j > sum - A[i]; j--)
			S[j]++;
	}
	for (int i = 1; i <= sum; i++)
		S[i] += S[i - 1];

	int rdx = 0;
	vector<int> cur = {0};
	dp[0][0] = 1;
	for (int i = 1; i <= sum; i++)
	{
		bitset<15005> valid = dp[i - 1];
		while(rdx <= M && B[rdx] * (sum - i) <= sum)
			cur.emplace_back(B[rdx++]);
				
		for (int k : cur)
			dp[i] = dp[i] | (valid << k);
		for (int j = S[i - 1]; j < S[i]; j++)
			dp[i][j] = 0;
	}
	//for (int i = 0; i <= sum; i++)
	//{
	//	cout << S[i] << "  ";
	//	for (int j = 0; j <= sum; j++)
	//		cout << dp[i][j] << " \n"[j == sum];
	//
	//}
	if(!dp[sum][sum])
	{	
		cout << -1 << '\n';
		return 0;
	}
	int last = sum;
	vector<int> sizes;
	vector<vector<int>> sol;
	cur.clear();
	for (int i = sum; i >= 1; i--)
	{
		if(!dp[i - 1][last])
		{
			int pre = 0;
			for (int j = M; j >= 1; j--)
				if(last >= B[j] && dp[i - 1][last - B[j]])
				{	
					pre = last - B[j];
				   	break;
				}
			sizes.emplace_back(last - pre);
			last = pre;
		}
	}
	//for (auto i : sizes)
	//	cout << i << ' ';
	//cout << endl;
	sort(sizes.begin(), sizes.end());
	sol.resize(sizes.size());	
	int f = 0, s = 0;
	for(int i : all)
	{
		sol[s].emplace_back(i);
		if(sol[s].size() == sizes[s])
			f = s + 1;
		s++;
		if(s == sizes.size())
			s = f;
	}
	cout << sol.size() << '\n';
	for (auto v : sol)
	{
		cout << v.size();
		for(auto i : v)
			cout << ' ' << i;
		cout << '\n';
	}
	
}
