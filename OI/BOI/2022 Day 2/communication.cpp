#include "communication.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct state
{
	int szA = 0, szB = 0;
	vector<pii> A, B;
};

// 11 -> 10 01 11
// 10 -> 10 00 11
// 00 -> 00 01

void split(state &s, state &L, state &R)
{
	auto &[szA, szB, A, B] = s;
	int lA = (szA + 1) / 2, lB = szB / 2;
	for (auto [l, r] : A)
	{
		if (r - l + 1 <= lA)
			L.A.emplace_back(pii(l, r));
		else if (lA <= 0)
			R.A.emplace_back(pii(l, r));
		else
		{
			L.A.emplace_back(pii(l, l + lA - 1));
			R.A.emplace_back(pii(l + lA, r));
		}
		lA -= r - l + 1;
	}
	R.B = L.A;
	L.B = R.A;
	for (auto [l, r] : B)
	{
		if (r - l + 1 <= lB)
			L.A.emplace_back(pii(l, r));
		else if (lB <= 0)
			R.A.emplace_back(pii(l, r));
		else
		{
			L.A.emplace_back(pii(l, l + lB - 1));
			R.A.emplace_back(pii(l + lB, r));
		}
		lB -= r - l + 1;
	}
}
/*
3 1 -> [2 1] [1+1 2]
2 2 -> [1 1] [1 1]
*/

pii divide(state s, int x, bool encode, int dep = 1)
{
	assert(dep <= 150);
	auto &[szA, szB, A, B] = s;
	for (auto [l, r] : A)
		szA += r - l + 1;
	for (auto [l, r] : B)
		szB += r - l + 1;
	// cerr << szA << ' ' << szB << '\n';
	// cerr << "divide " << szA << " A ";
	// for(auto [i, j] : A)
	// 	cerr << "[" << i << ", " << j << "] ";
	// cerr << szB << " B ";
	// for(auto [i, j] : B)
	// 	cerr << "[" << i << ", " << j << "] ";
	// cerr << '\n';
	if (szA <= 2 && szB <= 1)
	{
		vector<int> v;
		for (auto [l, r] : A)
			for (int i = l; i <= r; i++)
				v.emplace_back(i);
		while (v.size() < 2)
			v.emplace_back(encode ? 0 : 1);
		for (auto [l, r] : B)
			for (int i = l; i <= r; i++)
				v.emplace_back(i);
		while (v.size() < 3)
			v.emplace_back(encode ? 0 : 1);
		if (encode)
		{

			if (x == v[0])
				send(1), send(1);
			else if (x == v[1])
			{
				send(1);
				send(0);
			}
			else
				send(0), send(0);
			return pii(0, 0);
		}
		else
		{
			int res = receive() * 2;
			res += receive();
			if (res == 2 || res == 3)
				return pii(v[0], v[1]);
			else if (res == 1)
				return pii(v[0], v[2]);
			else
				return pii(v[1], v[2]);
		}
	}
	state L, R;
	split(s, L, R);
	int signal = 1;
	for (auto [l, r] : L.A)
		if (l <= x && x <= r)
			signal = 0;
	int res;
	if (encode)
		res = send(signal);
	else
		res = receive();

	if (res == 0)
		return divide(L, x, encode, dep + 1);
	else
		return divide(R, x, encode, dep + 1);
}

void encode(int N, int X)
{
	state s;
	s.A.emplace_back(pii(1, N));
	divide(s, X, 1);
}

pii decode(int N)
{
	state s;
	s.A.emplace_back(pii(1, N));
	return divide(s, 0, 0);
}
