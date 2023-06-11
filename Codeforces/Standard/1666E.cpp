#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define N 100015
using namespace std; 

int n, L, a[100005], b[100005];

bool checkK(int k)
{
	int last = 0;
	for(int i = 1; i <= n; i++)
		if(last > a[i])
			return 0;
		else
			last = max(a[i], last + k);
	if(last > L)
		return 0;
	return 1;
}

bool checkD(int k, int d)
{
	vector<pii> range(n + 1);
	for(int i = 1; i < n; i++)
		range[i] = pii(max(0LL, a[i] - i * k), min(d * i, a[i + 1] - i * k));
	range[n] = pii(L - n * k, L - n * k);
	for(int i = n - 1; i >= 1; i--)
	{
		pii r = range[i + 1];
		r.F -= d;
		range[i].F = max(range[i].F, r.F);
		range[i].S = min(range[i].S, r.S);
		
		if(range[i].F > range[i].S)
			return 0;
	}
	for(int i = 1; i <= n; i++)
		b[i] = max(b[i - 1], range[i].F);
	return 1;
}

signed main(){
	fast;
	cin >> L >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int kL = 1, kR = L;
	while(kL < kR)
	{
		int kmid = (kL + kR + 1) / 2;
		if(checkK(kmid))
			kL = kmid;
		else 
			kR = kmid - 1;
	}
	int k = kL, dL = 0, dR = L;
	while(dL < dR)
	{
		int dmid = (dL + dR) / 2;
		if(checkD(k, dmid))
			dR = dmid;
		else 
			dL = dmid + 1;
	}
	checkD(k, dL);
	for(int i = 1; i <= n; i++)
		b[i] += i * k;
	cerr << k << ' ' << dL << '\n';
	for(int i = 1; i <= n; i++)
	{
		cout << b[i - 1] << ' ' << b[i] << '\n';
		assert(b[i - 1] <= a[i] && a[i] <= b[i]);
	}
}
