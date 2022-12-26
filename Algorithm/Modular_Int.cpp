#include <bits/stdc++.h>

template <typename T = __int64, T mod = 1000000007>
struct modInt
{
    T val;
    modInt() : val(T()){};
    modInt(T init) : val(T(init)){};

    modInt operator=(T val)
    {
        this->val = val;
        return *this;
    }
    modInt operator+(modInt b)
    {
        return (val + b.val >= mod ? val + b.val - mod : val + b.val);
    }
    modInt &operator+=(modInt b)
    {
        this = this + b;
        return *this;
    }
    modInt operator-(modInt b)
    {
        return (val - b.val < 0 ? val - b.val + mod : val - b.val);
    }
    modInt &operator-=(modInt b)
    {
        this = this - b;
        return *this;
    }
};

int main()
{
}
