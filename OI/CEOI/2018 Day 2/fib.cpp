#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;




/*
Maintain maximal (in terms of reversed lexicographical order) form of current value
Property 1: there don't exist two position is 1 in both position

While updating, 
Case 1: ...110...
	converting into ...001..., it is equivlant to delete position i and add to position i + 1
	when encountering ...111..., convert lowest first.
Case 2: ...01010101020101...
	consider 
	00010102000 -> 
	00010200100 -> 
	00020010100 -> 
	01001010100
	it is equivlant to move down consecutive 10101010101's first by 2 position and shift others by 1
	notice that in this case, the highest bit may cause another case 1.
Corner Cases:
	consider insert two 2, we need to consider insert(0) as insert(1), which occurs in case 2,
	if we consider insert two 1, it calls insert(-1) and we should not do anything.

How to maintain?
	We need to know that
	(1) the left most position where 10101010101 (for some 1)
	we only cares about same parity, store each [L, R] in set.
	while query, find max L <= pos and check
	while modify, it is going to be
		(i) insert range, check both sides.
		(ii) remove range, check both sides shouldn't have zero length
	(2) current dp (using matrix)
	let dp[i][0] = for current prefix, we moved down (so that current position is 0)
		dp[i][1] = we didn't
	then dp[j][0] = dp[i][0] * length / 2 + dp[i][1] * (length - 1) / 2
		 dp[j][1] = dp[i][0] + dp[i][1]
	A way to maintain is using treap,
	we need to keep an record of matrix, left length, total length
	when insert, find left (we can split at most this position) and get right most one (in case there are no right most one, add a new node)
	when remove, find left most one and erase right most one and add somthing adding their length
	when adding or subtracting length, we can traverse until we find it and change it
	for case 1, add and keep erase and add
	for case 2, erase left most, add in left most, add length after next left most, add right and do case 1	
*/

struct FibTree
{
	struct consecutiveSet
	{
		map<ll, ll> mp;
		ll find(ll k)
		{

		}
		void insert(ll L, ll R)
		{

		}
		void remove(ll L, ll R)
		{

		}
	} cSet[2];

	struct Treap
	{
		struct node
		{
			ll sz, len, prefix, dp[2][2];		
		};
		node* root = nullptr;
		Treap *merge(Treap t)
		{
			
		}
		void split
	};
	Treap *bst;
}

signed main()
{
    int N;
    cin >> N;
    
}
