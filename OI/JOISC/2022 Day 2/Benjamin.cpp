#include "Benjamin.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll encode(int x, int y, int N)
{
	ll acc = 0;
	for(int i = 0; i < x; i++)
		acc += N - i - 1;
	return acc + y - x - 1;
}

ll q, r;

string SendB(int N, int X, int Y) 
{
	if(X > Y)
		swap(X, Y);
	
	q = encode(X, Y, N) >> 20;
	r = encode(X, Y, N) - (q << 20);
	
	string res;
	for(int i = 19; i >= 0; i--)
		res.push_back(((r >> i) & 1) ? '1' : '0');
	cerr << "Ben: Sent\n";
	return res;
}

int Answer(string T) 
{
	int ans = 0;
	for(int i = 0; i <= 13; i++)
		ans = (ans << 1) + (T[q * 14 + i] == '1');
	cerr << "Answer returned\n";
	return ans;
}
