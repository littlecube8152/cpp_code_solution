#include "manager.h"
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cassert>
#include <utility>
#include <map>
#include <functional>
using namespace std;

namespace {
map <vector <int>, int> tree;
int _id = 0;

int check_table(vector <int> a) {
	if (tree.count(a)) return tree[a];
	return tree[a] = _id++;
}

vector <int> get_value(int n, vector <vector <int>> g) {
	vector <int> sz(n + 1);
	function <void(int, int)> dfs_sz = [&](int v, int pa) {
		sz[v] = 1;
		for (int u : g[v]) if (u != pa) {
			dfs_sz(u, v), sz[v] += sz[u];
		}
	};
	function <bool(int)> check_cen = [&](int v) {
		dfs_sz(v, -1);
		for (int u : g[v]) if (sz[u] > n / 2) {
			return false;
		}
		return true;
	};
	function <int(int, int)> dfs_val = [&](int v, int pa) {
		vector <int> cur;
		for (int u : g[v]) if (u != pa) {
			cur.push_back(dfs_val(u, v));
		}
		sort(cur.begin(), cur.end());
		return check_table(cur);
	};

	vector <int> val;
	for (int i = 1; i <= n; ++i) if (check_cen(i)) {
		val.push_back(dfs_val(i, -1));
	}
	return val;
}

bool is_isomorphic(int n, vector <vector <int>> g1, vector <vector <int>> g2) {
	vector <int> val1 = get_value(n, g1);
	vector <int> val2 = get_value(n, g2);
	for (int x : val1) for (int y : val2) if (x == y) {
		return true;
	}
	return false;
}

bool is_tree(int n, vector <vector <int>> g) {
	vector <int> vis(n + 1, 0);
	bool cyc = false;
	function <void(int, int)> dfs = [&](int v, int pa) {
		vis[v] = 1;
		for (int u : g[v]) if (u != pa) {
			if (!vis[u]) {
				dfs(u, v);
			} else if (vis[u] == 1) {
				cyc = true;
			}
		}
		vis[v] = 2;
	};

	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		dfs(i, -1);
	}
	return !cyc;
}
}

int main () {
	int T, mxlen = 0;
	assert(1 == scanf("%d", &T));
	for (int i = 0; i < T; ++i) {
		int n;
		assert(1 == scanf("%d", &n));
		vector <pair <int, int>> edge(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			assert(2 == scanf("%d %d", &edge[i].first, &edge[i].second));
		}

		string s = Black(n, edge);

		if (s.length() > 300) {
			printf("Black(): String length is too long.\n");
			return 0;
		}

		for (char c : s) {
			if (c == '0' || c == '1')
				continue;
			printf("Black(): Invalid string character.\n");
			return 0;
		}

		vector <pair <int, int>> tree = White(s.length(), s);
		mxlen = max(mxlen, int(s.length()));

		if (tree.size() > 30) {
			printf("White(): The size of the output edge set is too big.\n");
			return 0;
		}

		vector <vector <int>> correct_tree(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			int u, v; tie(u, v) = edge[i];
			correct_tree[u].push_back(v);
			correct_tree[v].push_back(u);
		}

		if (tree.size() != n - 1) {
			printf("White(): The size of the output edge set is not correct.\n");
			return 0;
		}

		vector <vector <int>> output_tree(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			int u, v; tie(u, v) = tree[i];
			if (1 <= u && u <= n && 1 <= v && v <= n) {
				output_tree[u].push_back(v);
				output_tree[v].push_back(u);
			} else {
				printf("White(): The index of the output vertex is not in range [1, n].\n");
			}
		}

		if (!is_tree(n, output_tree)) {
			printf("White(): The output edge set is not a tree.\n");
		}

		if (!is_isomorphic(n, correct_tree, output_tree)) {
			printf("White(): The output tree is not isomorphic to the input tree.\n");
		}
	}
	printf("Accepted: %d\n", mxlen);
}