#include <bits/stdc++.h>
#define ll long long

#include "books.h"

using namespace std;
//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//

ll val[100005], used[100005];

ll getval(int i)
{
	if(val[i] == 0)
		val[i] = skim(i);
	return val[i];
}

void solve(int N, int K, long long A, int S) 
{
	vector<int> ans;
	ll sum = 0;
	for(int i = 1; i <= K; i++)
	{
		ans.emplace_back(i);
		sum += getval(i);
		used[i] = 1;
	}	
	if(sum > 2 * A)
	{
		impossible();
		return;
	}
	if(A <= sum)
	{
		answer(ans);
		return;
	}
	for(int i = 1; i <= K; i++)
	{
		cerr << "exchanging " << i << '\n';
		int L = 1, R = N;
		while(L < R)
		{
			int mid = (L + R + 1) / 2, m = -1;
			if(used[mid])
			{
				R = mid - 1;
				continue;
			}
			ll dif = 0;
			for(int j = 0; j < K; j++)
				if(getval(mid) - getval(ans[j]) + sum <= 2 * A)
					if(getval(mid) - getval(ans[j]) > dif)
						dif = getval(mid) - getval(ans[j]), m = j; 
			if(m >= 0) L = mid;
			else R = mid - 1;
		}
		if(!used[L])
		{
			int m = -1;
			ll dif = 0;
			for(int j = 0; j < K; j++)
				if(getval(L) - getval(ans[j]) + sum <= 2 * A)
					if(getval(L) - getval(ans[j]) > dif)
						dif = getval(L) - getval(ans[j]), m = j; 
			used[L] = 1;
			sum += getval(L) - getval(ans[m]);
			ans[m] = L;
		}
		else 
		{
			impossible();
			return;
		}
		if(A <= sum)
		{
			answer(ans);
			return;
		}
	}
	impossible();
}
