#include <bits/stdc++.h>
#define N 9
using namespace std;

int inv[N];

void build_inv()
{
    inv[1] = 1;
    for (int i = 2; i <= N; i++)
        inv[i] = ((N - (N / i)) * inv[N % i]) % N;
}

int main()
{
}