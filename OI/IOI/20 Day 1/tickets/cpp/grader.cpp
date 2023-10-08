#include "tickets.h"
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <bits/stdc++.h>

static int n;
static int m;
static int k;
static std::vector<std::vector<int>> d;
static std::vector<std::vector<int>> x;
static int called = 0;

static void check(bool cond, std::string message) {
    if (!cond) {
        printf("%s\n", message.c_str());
        exit(0);
    }
}


void allocate_tickets( std::vector<std::vector<int>> _d) {
    check(!called, "allocate_tickets called more than once");
    d = _d;
    check((int)d.size() == n, "allocate_tickets called with parameter of wrong size");
    for (int i = 0; i < n; i++) {
        check((int)d[i].size() == m, "allocate_tickets called with parameter of wrong size");
    }
    called = 1;
}

int main() {
    assert(scanf("%d %d %d", &n, &m, &k) == 3);
    x.resize(n);
    for (int i = 0; i < n; i++) {
        x[i].resize(m);
        for (int j=0; j < m; j++) {
            assert(scanf("%d", &x[i][j]) == 1);
        }
    }
    fclose(stdin);

    long long answer = find_maximum(k, x);
    check(called, "failure to call allocate_tickets");
    printf("%lld\n", answer);
    std::vector<int> round[k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(d[i][j] >= 0)
                round[d[i][j]].emplace_back(x[i][j]);
            if (j) printf(" ");
            printf("%d", d[i][j]);
        }
        printf("\n");
    }
    long long calc = 0;
    for (int i = 0; i < k; i++)
    {
        std::sort(round[i].begin(), round[i].end());
        for (int j = 0; j < n / 2; j++)
            calc -= round[i][j];
        for (int j = n / 2; j < n; j++)
            calc += round[i][j];
    }
    printf("checked ans: %lld\n", calc);
    fclose(stdout);
    return 0;
}
