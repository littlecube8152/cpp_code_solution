#include <iostream>
using namespace std;
int main()
{
    long long int M, N, result = 0;
    cin >> N;
    for (long long int i = 0; i < N; i++)
    {
        long long int tmp;
        cin >> tmp;
        result += tmp;
    }
    cin >> M;
    for (long long int i = 0; i < M; i++)
    {
        long long int l, r, w;
        cin >> l >> r >> w;
        result += ((r - l + 1) * w);
        cout << result << '\n';
    }
}