#include "vision.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int id[405][405], last, zero;

void construct_network(int H, int W, int K)
{
	if (H * W == 2)
	{
		add_or({0, 1});
		return;
	}

	last = H * W;
	for (int i = 1; i < H + W; i++)
		for (int j = 1; j < H + W; j++)
			id[i][j] = -1;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			id[j + i + 1][H - i + j] = i * W + j;

	vector<int> Hs(H + W), Ws(H + W);
	for (int i = 1; i < H + W; i++)
	{
		vector<int> input;
		for (int j = 1; j < H + W; j++)
			if (id[i][j] >= 0)
				input.emplace_back(id[i][j]);
		Hs[i] = last++;
		add_or(input);
	}
	for (int j = 1; j < H + W; j++)
	{
		vector<int> input;
		for (int i = 1; i < H + W; i++)
			if (id[i][j] >= 0)
				input.emplace_back(id[i][j]);
		Ws[j] = last++;
		add_or(input);
	}

	vector<int> HeqK, HgeK, WeqK, WgeK;

	for (int i = 1; i + K < H + W; i++)
	{
		HeqK.emplace_back(last++);
		add_and({Hs[i], Hs[i + K]});
	}

	for (int j = 1; j + K < H + W; j++)
	{
		WeqK.emplace_back(last++);
		add_and({Ws[j], Ws[j + K]});
	}

	for (int i = 1; i + K + 1 < H + W; i++)
	{
		vector<int> input;
		for (int j = i + K + 1; j < H + W; j++)
			input.emplace_back(Hs[j]);
		add_or(input);
		++last;
		add_and({Hs[i], last - 1});
		HgeK.emplace_back(last++);
	}

	for (int i = 1; i + K + 1 < H + W; i++)
	{
		vector<int> input;
		for (int j = i + K + 1; j < H + W; j++)
			input.emplace_back(Ws[j]);
		add_or(input);
		++last;
		add_and({Ws[i], last - 1});
		WgeK.emplace_back(last++);
	}

	if (HeqK.empty())
		add_and({0, 1, 2});
	else
		add_or(HeqK);

	if (WeqK.empty())
		add_and({0, 1, 2});
	else
		add_or(WeqK);

	if (HgeK.empty())
		add_and({0, 1, 2});
	else
		add_or(HgeK);

	if (WgeK.empty())
		add_and({0, 1, 2});
	else
		add_or(WgeK);

	add_or({last, last + 1}); // last + 4 = if dis == K
	add_not(last + 2);		  // last + 5 = if H <= K
	add_not(last + 3);		  // last + 6 = if W <= K
	add_and({last + 4, last + 5, last + 6});
}
