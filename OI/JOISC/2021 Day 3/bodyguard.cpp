#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct hoM
{
	int y, xl, xr;
	ll c;
};

struct verM
{
	int x, y;
	bool io;
	ll c;
};

struct Qu
{
	int y, x, i;
}

int N, Q, idx = 0;
vector<hoM> homod;
vector<verM> vermod;
vector<pii> query;
vector<int> seg, l = {0}, r = {0};
vector<pll> lct = {pll{0, 0}};

void modify(pll line, int i, int L, int R)
{
	int mid = (L + R) / 2;
	if(line.F * mid + line.S > lct[i].F * mid + lct[i].S)
		swap(line, lct[i]);
	if(L != R && line != pll{0, 0})
	{
		if(line.S * lct[i].F <= lct[i].S * line.F)
		{
			if(l[i] == 0)
			{
				l[i] = ++idx;
				newnode();
			}
			modify(line, l[i], L, mid);
		}
		else
		{
			if(r[i] == 0)
			{
				r[i] = ++idx;
				newnode();
			}
			modify(line, r[i], mid + 1, R);
		}
	}
}

void newnode()
{
	l.emplace_back(0), r.emplace_back(0);
	lct.emplace_back({0, 0});
}

void spilt(pll line, int mL, int mR, int i = 0, int L = 1, int R = 1e9)
{
	if(mL <= L && R <= mR)
		modify(line, i, L, R);
	else if(R < mL || mR < L)
		return;
	else
	{
		int mid = (L + R) / 2;
		if(l[i] == 0)
		{
			l[i] = ++idx;
			newnode();
		}
		spilt(line, mL, mR, l[i], L, mid);
		if(r[i] == 0)
		{
			r[i] = ++idx;
			newnode();
		}
		spilt(line, mL, mR, r[i], mid + 1, R);
	}
}

ll query(ll pos, int i = 0, int L = 1, int R = 1e9)
{
	if(lct[i] == {0, 0})
		return 0;
	int mid = (L + R) / 2;
	if(L != R)
	{
		if(pos <= mid && l[i])
			return max(lct[i].F * pos + lct[i].S, query(pos, l[i], L, mid);
		else if(pos > mid && r[i])
			return max(lct[i].F * pos + lct[i].S, query(pos, r[i], mid + 1, R);
	}
	return lct[i].F * pos + lct[i].S;
}

signed main()
{
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
	{
		int T, A, B, C;
		cin >> T >> A >> B >> C;
		if(B < A)
		{	
			seg.emplace_back(T + A);
			vermod.emlpace_back({T + A, 2 * B - A - T, 1, C});
			vermod.emlpace_back({T + A, A - T, 1, C});
		}
		else
		{
			seg.emplace_back(T + 2 * B - A);
			seg.emplace_back(T + A);
			homod.emplace_back({A - T, T + A, 1, + 2 * B - A, 0, C});
		}
	}
	sort(vermod.begin(), vermod.end());
	sort(homod.begin(), homod.end());
	sort(seg.begin(), seg.end());
	seg.resize(unique(seg.begin(), seg.end()) - seg.begin());
	for(int i = 1; i <= Q; i++)
	{
		int P, X;
		cin >> P >> X;
		query.emplace_back({P - X, X + P, i});
	}
	sort(query.begin(), query.end());
	int vdx = 0, hdx = 0, qdx = 0;
	while(!query.empty())
	{
		int mxt = max((vdx < vermod.size() ? vermod[vdx].x
	}
}
