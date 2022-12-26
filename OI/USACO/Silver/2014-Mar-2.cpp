#include <fstream>
#define ll long long
using namespace std;

ll N, K, pre[2405][2405], ans;
signed main()
{
    ifstream fin("lazy.in");
    fin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> pre[2 * N + j + i + 1][3 * N + j - i - 1];
    fin.close();
    for (int i = 1; i <= 6 * N; i++)
        for (int j = 1; j <= 6 * N; j++)
            pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int x = 2 * N + j + i + 1, y = 3 * N + j - i - 1;
            ans = max(ans, pre[x + K][y + K] - pre[x - K - 1][y + K] - pre[x + K][y - K - 1] + pre[x - K - 1][y - K - 1]);
        }
    ofstream fout("lazy.out");
    fout << ans << endl;
    fout.close();
}