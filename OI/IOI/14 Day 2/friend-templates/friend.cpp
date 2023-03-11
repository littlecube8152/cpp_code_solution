#include "friend.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p[100002], q[100002];

// Find out best sample
int findSample(int n, int confidence[], int host[], int protocol[])
{
	for (int i = n - 1; i >= 0; i--)
		p[i] = confidence[i], q[i] = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (protocol[i] == 0)
		{
			q[host[i]] = max(q[host[i]] + q[i], q[host[i]] + p[i]);
			p[host[i]] = p[host[i]] + q[i];
		}
		else if (protocol[i] == 1)
		{
			p[host[i]] = max({p[host[i]] + q[i], p[host[i]] + p[i], q[host[i]] + p[i]});
			q[host[i]] += q[i];
		}
		else
		{
			p[host[i]] = max({p[host[i]] + q[i], q[host[i]] + p[i]});
			q[host[i]] += q[i];
		}
	}
	return max(p[0], q[0]);
}
