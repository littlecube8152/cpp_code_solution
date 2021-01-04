#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    fstream file; //宣告fstream物件

    char str[3] = "1 ";
    int t = 100000;

    file.open("Reader.txt", ios::out | ios::trunc);

    while (t--)
        file.write(str, 2); //將str寫入檔案

    file.close(); //關閉檔案
}