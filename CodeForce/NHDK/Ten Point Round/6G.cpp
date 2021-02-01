#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, n;
ll sa = 0, sb = 0;
priority_queue<int> a, b;

void draw(int k)
{
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        b.emplace(x);
    }
}

signed main()
{

    cin >> t >> n;
    draw(t);

    for (int i = 0; i < n; i++)
    {
        if (a.top() > b.top())
        {
            sa += 5;
            sb += 3;
            a.pop();
            b.pop();
            draw(3);
            a.pop();
            a.pop();
            b.pop();
        }
        else if (a.top() < b.top())
        {
            sa += 3;
            sb += 5;
            a.pop();
            b.pop();
            draw(3);
            a.pop();
            b.pop();
            b.pop();
        }
        else if (a.top() == b.top())
        {
            sa += 3;
            sb += 3;
            a.pop();
            b.pop();
            draw(3);
        }
    }
    cout << sa << " " << sb << '\n';
}