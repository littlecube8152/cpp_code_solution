#ifndef EVAL
#include "grader.cpp"
#endif
#include "ancient2.h"
#include <bits/stdc++.h>
using namespace std;

namespace
{

    int variable_example = 1;

} // namespace

string Solve(int N)
{
    string s;
    for (int i = 0; i < N / 2; i++)
    {
        // messy strat:
        int mxj = -1, cost = i + 3;
        for (int j = 1; j < i; j++)
            if (s[i - 1] != s[i - 1 - j])
            {
                vector<char> cycle;
                for (int k = i - 1; k >= 0; k -= j)
                    cycle.emplace_back(s[k]);
                cycle.resize(unique(cycle.begin(), cycle.end()) - cycle.begin());
                int rc = (cycle.size() - 1) * j + 3;
                if (rc < cost)
                    mxj = j, cost = rc;
            }

        if (mxj == -1) // fall back to normal strat
        {
            vector<int> a(i + 3), b(i + 3);
            for (int j = 0; j < i; j++)
                a[j] = b[j] = j + 1;
            a[i] = i + 2;
            b[i] = i + 1;
            a[i + 1] = i + 1;
            b[i + 1] = i + 1;
            a[i + 2] = i + 2;
            b[i + 2] = i + 2;
            int res = Query(i + 3, a, b);
            if (res == i + 1)
                s.push_back('1');
            else
                s.push_back('0');
        }
        else // apply messy strat
        {
            int m = 0;
            vector<int> a, b;
            int r = (i - 1) % mxj;
            for (int k = (i - 1) % mxj; k < i - 1; k += mxj)
            {
                while (k + mxj < i && s[k] == s[k + mxj])
                    k += mxj;
                for (int p = 0; p < mxj; p++)
                {
                    a.emplace_back(m + (p + 1) % mxj);
                    b.emplace_back(m + (p + 1) % mxj);
                }
                if (s[k] == '0')
                    b[m + r] = m + mxj;
                else
                    a[m + r] = m + mxj;
                r = mxj - 1;
                m += mxj;
            }

            a.emplace_back(m + 1);
            b.emplace_back(m + 2);
            a.emplace_back(m + 1);
            b.emplace_back(m + 1);
            a.emplace_back(m + 2);
            b.emplace_back(m + 2);
            int res = Query(m + 3, a, b);
            if (res == m + 1)
                s.push_back('0');
            else
            {
                assert(res == m + 2);
                s.push_back('1');
            }
        }
    }
    for (int i = N / 2; i < N; i++)
    {
        // jump strat: cost = t.size() + N - i
        string t = s;
        t.resize(unique(t.begin(), t.end()) - t.begin());

        // messy strat:
        int mxj = -1, cost = t.size() + N - i;
        for (int j = 1; j < i; j++)
            if (s[i - 1] != s[i - 1 - j])
            {
                vector<char> cycle;
                for (int k = i - 1; k >= 0; k -= j)
                    cycle.emplace_back(s[k]);
                cycle.resize(unique(cycle.begin(), cycle.end()) - cycle.begin());
                int rc = (cycle.size() - 1) * j + 3;
                if (rc < cost)
                    mxj = j, cost = rc;
            }

        if (mxj == -1) // fall back to jump strat
        {
            int m = 0;
            vector<int> a, b;
            for (char d : t)
                if (d == '0')
                {
                    m++;
                    a.emplace_back(m - 1);
                    b.emplace_back(m);
                }
                else
                {
                    m++;
                    a.emplace_back(m);
                    b.emplace_back(m - 1);
                }
            for (int j = i; j < N; j++)
            {
                m++;
                a.emplace_back(m);
                b.emplace_back(m);
            }
            a.back() = m - 1;
            b.back() = m - 1;
            int res = Query(m, a, b);
            while (res < m - 1 && i < N)
                s.push_back(t.back()), i++, res++;
            if (i < N)
                s.push_back(t.back() ^ 1);
        }
        else // apply messy strat
        {
            int m = 0;
            vector<int> a, b;
            int r = (i - 1) % mxj;
            for (int k = (i - 1) % mxj; k < i - 1; k += mxj)
            {
                while (k + mxj < i && s[k] == s[k + mxj])
                    k += mxj;
                for (int p = 0; p < mxj; p++)
                {
                    a.emplace_back(m + (p + 1) % mxj);
                    b.emplace_back(m + (p + 1) % mxj);
                }
                if (s[k] == '0')
                    b[m + r] = m + mxj;
                else
                    a[m + r] = m + mxj;
                r = mxj - 1;
                m += mxj;
            }

            a.emplace_back(m + 1);
            b.emplace_back(m + 2);
            a.emplace_back(m + 1);
            b.emplace_back(m + 1);
            a.emplace_back(m + 2);
            b.emplace_back(m + 2);
            int res = Query(m + 3, a, b);
            if (res == m + 1)
                s.push_back('0');
            else
            {
                assert(res == m + 2);
                s.push_back('1');
            }
        }
    }
    return s;
}
