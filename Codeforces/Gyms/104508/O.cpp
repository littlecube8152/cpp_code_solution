#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
struct RollbackUF
{
    vi e;
    vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t)
    {
        for (int i = time(); i-- > t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
struct Edge
{
    int a, b;
    ll w;
};
struct Node
{ /// lazy skew heap node
    Edge key;
    Node *l, *r;
    ll delta;
    void prop()
    {
        key.w += delta;
        if (l)
            l->delta += delta;
        if (r)
            r->delta += delta;
        delta = 0;
    }
    Edge top()
    {
        prop();
        return key;
    }
};
Node *merge(Node *a, Node *b)
{
    if (!a || !b)
        return a ?: b;
    a->prop(), b->prop();
    if (a->key.w > b->key.w)
        swap(a, b);
    swap(a->l, (a->r = merge(b, a->r)));
    return a;
}
void pop(Node *&a)
{
    a->prop();
    a = merge(a->l, a->r);
}

pair<ll, vi> dmst(int n, int r, vector<Edge> &g)
{
    RollbackUF uf(n);
    vector<Node *> heap(n);
    for (Edge e : g)
        heap[e.b] = merge(heap[e.b], new Node{e});
    ll res = 0;
    vi seen(n, -1), path(n), par(n);
    seen[r] = r;
    vector<Edge> Q(n), in(n, {-1, -1}), comp;
    deque<tuple<int, int, vector<Edge>>> cycs;
    rep(s, 0, n)
    {
        int u = s, qi = 0, w;
        while (seen[u] < 0)
        {
            if (!heap[u])
                return {-1, {}};
            Edge e = heap[u]->top();
            heap[u]->delta -= e.w, pop(heap[u]);
            Q[qi] = e, path[qi++] = u, seen[u] = s;
            res += e.w, u = uf.find(e.a);
            if (seen[u] == s)
            { /// found cycle, contract
                Node *cyc = 0;
                int end = qi, time = uf.time();
                do
                    cyc = merge(cyc, heap[w = path[--qi]]);
                while (uf.join(u, w));
                u = uf.find(u), heap[u] = cyc, seen[u] = -1;
                cycs.push_front({u, time, {&Q[qi], &Q[end]}});
            }
        }
        rep(i, 0, qi) in[uf.find(Q[i].b)] = Q[i];
    }

    for (auto &[u, t, comp] : cycs)
    { // restore sol (optional)
        uf.rollback(t);
        Edge inEdge = in[u];
        for (auto &e : comp)
            in[uf.find(e.b)] = e;
        in[uf.find(inEdge.b)] = inEdge;
    }
    rep(i, 0, n) par[i] = in[i].a;
    return {res, par};
}

int n, adj[60][60], hang[60][60], t;
string s[60];
vector<int> E[60];
vector<int> nxt[26];
vector<pair<int, char>> ans = {{-1, ' '}};

void restore(int u, int par)
{
    vector<int> ids;
    for (char c : s[u])
    {
        ids.emplace_back(par);
        if (nxt[c - 'a'][par] == 0)
        {
            for (int j = 0; j < 26; j++)
                nxt[j].emplace_back(0);
            nxt[c - 'a'][par] = ++t;
            ans.emplace_back(make_pair(par, c));
        }
        par = nxt[c - 'a'][par];
    }
    for (auto v : E[u])
        restore(v, ids[hang[u][v]]);
}

signed main()
{
    ifstream cin("dictionary.in");
    ofstream cout("dictionary.out");
    for (int i = 0; i < 26; i++)
        nxt[i].emplace_back(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<Edge> g;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                // hang j onto i
                int p = 0, lcs = 0;
                for (int k = 0; k < s[i].size(); k++)
                {
                    int l = 0;
                    for (; k + l < s[i].size() && l < s[j].size(); l++)
                        if (s[i][k + l] != s[j][l])
                            break;
                    if (l > lcs)
                        p = k, lcs = l;
                }
                adj[i][j] = lcs, hang[i][j] = p;
                g.emplace_back(Edge{i, j, -lcs});
            }
    int w = 8, r = -1;
    vi sol;
    for (int i = 0; i < n; i++)
    {
        auto [nw, nsol] = dmst(n, i, g);
        if (nw < w)
            w = nw, sol = nsol, r = i;
    }

    for (int i = 0; i < n; i++)
        if (i != r)
            E[sol[i]].emplace_back(i);

    restore(r, 0);
    cout << t + 1 << '\n';
    for (auto [p, c] : ans)
        cout << p + 1 << ' ' << c << '\n';
}
