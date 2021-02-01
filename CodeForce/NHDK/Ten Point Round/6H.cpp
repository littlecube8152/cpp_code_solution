#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    Node *front;
    Node *back;
    int id;
};

Node a[200005];
signed main()
{
    int n, q;
    cin >> n;

    a[0].front = nullptr;
    a[0].back = &a[1];
    a[0].id = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i].front = &a[i - 1];
        a[i].back = &a[i + 1];
        a[i].id = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        a[y].back->front = a[y].front;
        a[y].front->back = a[y].back;
        a[y].front = a[x].front;
        a[y].back = &a[x];
        a[x].front->back = &a[y];
        a[x].front = &a[y];
        
    }
    Node *b = a[0].back;
    for (int i = 1; i <= n; i++)
    {
        cout << b->id << " \n"[i == n];
        b = b->back;
    }
}