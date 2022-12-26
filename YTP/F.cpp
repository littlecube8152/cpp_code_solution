#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int T;

int weight(char c)
{
    if (c == 'N')
        return 4;
    if (c == 'S')
        return 3;
    if (c == 'H')
        return 2;
    if (c == 'D')
        return 1;
    if (c == 'C')
        return 0;
    assert(0);
}

char nxt(char c)
{
    if (c == 'N')
        return 'E';
    if (c == 'E')
        return 'S';
    if (c == 'S')
        return 'W';
    if (c == 'W')
        return 'N';
    assert(0);
}

int card(string s)
{
    int F, S;
    if (s[1] == 'A')
        F = 14;
    else if (s[1] == 'K')
        F = 13;
    else if (s[1] == 'Q')
        F = 12;
    else if (s[1] == 'J')
        F = 11;
    else if (s[1] == 'T')
        F = 10;
    else
        F = s[1] - '0';
    S = weight(s[0]);
    return F * 6 + S;
}

int cardweight(string s, char king, char first)
{
    return card(s) + (s[0] == king ? 1000 : 0) + (s[0] == first ? 500 : 0);
}

int position(char c)
{
    if (c == 'N')
        return 0;
    if (c == 'E')
        return 1;
    if (c == 'S')
        return 2;
    if (c == 'W')
        return 3;
    assert(0);
}

void solve()
{
    string s, t, last = "0C", xlast = " ";
    char current, first[5] = {}, king = 'N';
    bool exist[1000] = {}, nocolor[5][5] = {{}}, valid = 1;
    int pass = -1, x = 0, score;
    cin >> current;
    while (cin >> t)
    {
        if (t == "PASS")
        {
            pass++;
            if (pass == 3)
                break;
        }
        else if (t == "X")
        {
            if (xlast != "" || x % 2 != 1)
                valid = 0;
            pass = 0;
            xlast = t;
            x = 0;
        }
        else if (t == "XX")
        {
            if (xlast != "X" || x % 2 != 1)
                valid = 0;
            pass = 0;
            x = 0;
            xlast = t;
        }
        else
        {
            if (t[0] < last[0] || (t[0] == last[0] && weight(t[1]) <= weight(last[1])))
                valid = 0;
            last = t;
            if (first[weight(t[1])] == 0)
                first[weight(t[1])] = current;
            xlast = "";
            x = 0;
            pass = 0;
        }
        x++;
        current = nxt(current);
    }

    if (last == "0C" && valid)
    {
        cout << "ALL PASS\n";
        return;
    }

    if (!valid)
    {
        for (int i = 1; i <= 52; i++)
            cin >> s;
        cout << "error\n";
        // cerr << 1 << '\n';
        return;
    }

    king = last[1];
    current = first[weight(king)];
    assert(current != 0);
    score = -(6 + last[0] - '0');

    // cerr << score << '\n';

    char master = nxt(current), player, fir;
    for (int i = 1; i <= 13; i++)
    {
        cin >> s;
        
        fir = s[0];

        if (exist[card(s)])
            valid = 0;
        exist[card(s)] = 1;

        if (nocolor[position(master)][weight(s[0])])
            valid = 0;

        vector<pair<int, char>> round;
        round.emplace_back(make_pair(cardweight(s, king, fir), master));
        player = nxt(master);

        for (int j = 1; j <= 3; j++)
        {

            cin >> t;
            if (exist[card(t)])
                valid = 0;
            exist[card(t)] = 1;

            if (nocolor[position(player)][weight(t[0])])
                valid = 0;
            if (s[0] != t[0])
                nocolor[position(player)][weight(s[0])] = 1;

            round.emplace_back(make_pair(cardweight(t, king, fir), player));
            player = nxt(player);
        }
        assert(player == master);
        sort(round.begin(), round.end(), greater<>());
        if (round[0].S == current || round[0].S == nxt(nxt(current)))
            score++;
        // cout << round[0].S << '\n';
        master = round[0].S;
    }
    if (!valid)
        cout << "error\n";
    else
    {
        cout << last << xlast << current;
        if (score == 0)
            cout << "=\n";
        else if (score < 0)
            cout << '-' << abs(score) << '\n';
        else
            cout << '+' << score << '\n';
    }
}

signed main()
{
    cin >> T;
    while (T--)
        solve();
}
