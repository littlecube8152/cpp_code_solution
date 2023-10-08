#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct treap
{
    int pri, size;
    // val
    treap *l, *r;
    treap(/*val*/) : pri(rd()), size(1), l(nullptr), r(nullptr){};
    treap() : pri(rd()), size(1), l(nullptr), r(nullptr){};
    void pull()
    {
        size = (l == nullptr ? 0 : l->size) + (r == nullptr ? 0 : r->size) + 1;
    }
    void push();
};

void spilt(int cnt, treap *root, treap *&left, treap *&right)
{
    if (root == nullptr)
    {
        left = right = nullptr;
        return;
    }
    root->push();
    int lsize = (root->l != nullptr ? root->l->size : 0);
    if (cnt >= lsize + 1)
    {   
        left = root;
        spilt(cnt - lsize - 1, left->r, left->r, right);
        left->pull();
    }
    else
    {
        right = root;
        spilt(cnt, right->l, left, right->l);
        right->pull();
    }
}

treap *merge(treap *left, treap *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    if (left->pri < right->pri)
    {
        left->push();
        left->r = merge(left->r, right);
        left->pull();
        return left;
    }
    else
    {
        right->push();
        right->l = merge(left, right->l);
        right->pull();
        return right;
    }
}