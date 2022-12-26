#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, Q, p[100005], pos[100005], pp[100005];

struct segTree
{
	ll sumL[400005] = {}, sumR[400005] = {}, lazyL[400005] = {}, lazyR[400005] = {}, sum[400005] = {};
	ll N;
	void setN(int n)
	{
		N = n;
	}
	ll getval(int i, int L, int R)
	{
		return sum[i] + sumL[i] * lazyR[i] + sumR[i] * lazyL[i] + (pp[R] - pp[L - 1]) * lazyL[i] * lazyR[i];
	}

	void push(int i, int L, int R)
	{
		lazyL[i << 1] += lazyL[i];
		lazyR[i << 1] += lazyR[i];
		lazyL[i << 1 | 1] += lazyL[i];
		lazyR[i << 1 | 1] += lazyR[i];
		sum[i] = getval(i, L, R);
		lazyL[i] = lazyR[i] = 0;
	}
	void modify(int mL, int mR, int val, bool isL, int i = 1, int L = 1, int R = -1)
	{
		
		if(R == -1)
			R = N;
		if(mL <= L && R <= mR)
			lazyL[i] += isL * val, lazyR[i] += (1 - isL) * val;
		else if(R < mL || mR < L)
			return;
		else
		{
			push(i, L, R);
			int mid = (L + R) / 2;
			modify(mL, mR, val, isL, i << 1, L, mid);
			modify(mL, mR, val, isL, i << 1 | 1, mid + 1, R);
			sum[i] = getval(i << 1, L, mid) + getval(i << 1 | 1, mid + 1, R);
			sumL[i] = sumL[i << 1] + (pp[mid] - pp[L - 1]) * lazyL[i << 1] + sumL[i << 1 | 1] + (pp[R] - pp[mid]) * lazyL[i << 1 | 1];
			sumR[i] = sumR[i << 1] + (pp[mid] - pp[L - 1]) * lazyR[i << 1] + sumR[i << 1 | 1] + (pp[R] - pp[mid]) * lazyR[i << 1 | 1];
		}
	}
	void debug(int i = 1, int L = 1, int R = -1)
	{
		if(R == -1)
			R = N;
		// printf("%d:[%d,%d], sum %lld, sumL %lld, sumR %lld, lazyL %lld, lazyR %lld\n", i, L, R, sum[i], sumL[i], sumR[i],lazyL[i], lazyR[i]);
		if(L != R)
		{
			int mid = (L + R) / 2;
			debug(i << 1, L, mid);
			debug(i << 1 | 1, mid + 1, R);
		}
	}
}seg[2];

set<int> st;

signed main()
{
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
	{	
		cin >> pos[i];
		p[pos[i]] = i;
		
	}
	for(int i = 1; i <= N; i++)
		pp[i] = pp[i - 1] + p[i];
	seg[0].setN(N);
	seg[1].setN(N);
	st.insert(0);
	st.insert(N + 1);
	for(int i = N; i >= 1; i--)
	{
		auto it = st.lower_bound(pos[i]);
		seg[0].modify(pos[i], pos[i], *it - pos[i], 0);
		it = prev(it);
		seg[0].modify(pos[i], pos[i], pos[i] - *it, 1);
		st.insert(pos[i]);
		// seg[0].debug();
	}
	st.clear();
	st.insert(0);
	st.insert(N + 1);
	for(int i = 1; i <= N; i++)
	{
		auto it = st.lower_bound(pos[i]);
		seg[1].modify(pos[i], pos[i], *it - pos[i], 0);
		it = prev(it);
		seg[1].modify(pos[i], pos[i], pos[i] - *it, 1);
		st.insert(pos[i]);
	}
	cout << seg[0].getval(1, 1, N) - seg[1].getval(1, 1, N) + N * (N + 1) / 2 << '\n';
}
