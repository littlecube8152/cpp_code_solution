    #pragma GCC optimize("O0,unroll-loops")
    #include <bits/stdc++.h>
    #define ll long long
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define F first
    #define S second
    using namespace std;

    int N;

    time_t a, b;

    int i_think_it_should_work()
    {
        volatile ll v[8950000];
        return 1;
    }

    void hope_this_will_work()
    {
        if (N == 4)
        {
            for (int i = 1; i <= 31000; i++)
                malloc(2049);
            exit(0);
        }
        else if (N == 5)
        {
            string s = string(130000, ' ');
            for (int i = 1; i <= 68; i++)
                cout << s;
            exit(0);
        }
        else if (N == 6)
            exit(1);
        else if (N == 7)
        {
            bool L[0];
            N = L[rand()];
            exit(0);
        }
        else if (N == 9)
            while (clock() - a <= CLOCKS_PER_SEC * 0.997)
                ;
    }

    signed main()
    {
        a = clock();
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        cin >> N;
        if (N != 1)
            cout << N << endl;
        if (N <= 1)
            return 0;
        if (N == 2)
            while (1)
                ;
        if (N == 3)
        {
            int *L = new int[15500000LL];
            return 0;
        }
        if (N == 8)
        {
            int *L = new int[1200000];
            return 0;
        }
        else if (N >= 4)
            hope_this_will_work();
    }