#include "mushrooms.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
60:  91.8699
70:  92.2449 
80:  92.623 (244 queries)
85:  92.623
90:  92.2449
95:  92.2449
100: 92.2449
110: 91.129
*/
int k = 87;

int count_mushrooms(int n)
{
	int A = 0, B = 0;
	// small case
	if (n <= 226)
	{
		A = 1;
		for (int i = 1; i < n; i++)
			if (!use_machine({0, i}))
				A++;
		return A;
	}

	vector<int> a, b;
	a.emplace_back(0);
	for (int i = 1; i < 3; i++)
		if (use_machine({0, i}))
			b.push_back(i);
		else
			a.push_back(i);
	if (a.size() >= 2)
	{
		int a1 = a[0], a2 = a[1];
		for (int i = 3; i < 2 * k - 1; i += 2)
		{
			int result = use_machine({a1, i, a2, i + 1});
			if (result == 0)
				a.push_back(i), a.push_back(i + 1);
			else if (result == 1)
				a.push_back(i), b.push_back(i + 1);
			else if (result == 2)
				b.push_back(i), a.push_back(i + 1);
			else if (result == 3)
				b.push_back(i), b.push_back(i + 1);
		}
	}
	else
	{
		int b1 = b[0], b2 = b[1];
		for (int i = 3; i < 2 * k - 1; i += 2)
		{
			int result = use_machine({b1, i, b2, i + 1});
			if (result == 3)
				a.push_back(i), a.push_back(i + 1);
			else if (result == 2)
				a.push_back(i), b.push_back(i + 1);
			else if (result == 1)
				b.push_back(i), a.push_back(i + 1);
			else if (result == 0)
				b.push_back(i), b.push_back(i + 1);
		}
	}

	// not too small case
	if (n <= 2 * k - 1)
		return a.size();

	// big case
	for (int i = 2 * k - 1; i < n; i += k)
	{
		k = max(a.size(), b.size());
		if (a.size() >= k)
		{
			vector<int> q;
			int cnt = 0;
			for (int j = 0; j < k && i + j < n; j++)
			{
				q.emplace_back(a[j]);
				q.emplace_back(i + j);
				cnt++;
			}
			int result = use_machine(q);
			int dB = (result + 1) / 2, dA = cnt - dB;
			A += dA;
			if (result % 2 == 1)
				b.emplace_back(q.back());
			else
				a.emplace_back(q.back()), A--;
		}
		else
		{
			vector<int> q;
			int cnt = 0;
			for (int j = 0; j < k && i + j < n; j++)
			{
				q.emplace_back(b[j]);
				q.emplace_back(i + j);
				cnt++;
			}
			int result = use_machine(q);
			int dA = (result + 1) / 2;
			A += dA;
			if (result % 2 == 1)
				a.emplace_back(q.back()), A--;
			else
				b.emplace_back(q.back());
		}
	}
	return a.size() + A;
}
