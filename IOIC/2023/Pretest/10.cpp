#pragma GCC optimize("Ofast,unroll-loops")
#include <cstdio>
#include <array>
#define ll long long
using namespace std;

const int mod = 10007;
int a, b, c, d;
bool o[10007];
int cnt;


constexpr std::array<int, mod> get_2()
{
    std::array<int, mod> arr{};
    for (int i = 1; i < mod; i++)
        arr[i] = i * i % mod;
    return arr;
}

constexpr std::array<int, mod> get_3()
{
    std::array<int, mod> arr{};
    for (int i = 1; i < mod; i++)
        arr[i] = i * i % mod * i % mod;
    return arr;
}

constexpr std::array<int, mod>  two = get_2(), three = get_3();

signed main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a = a % mod;
    b = b % mod;
    c = c % mod;
    d = d % mod;
    for (int i = 0; i < mod; i++)
        if ((a * three[i] + b * two[i] + c * i + d) % mod == 0)
            o[i] = ++cnt;
    printf("%d\n", cnt);
    for (int i = 0; i < mod; i++)
        if (o[i])
            printf("%d\n", i);
}