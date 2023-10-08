int quad(pll p)
{
    // alternative equal
    if (p.F > 0 && p.S >= 0)
        return 1;
    if (p.F <= 0 && p.S > 0)
        return 2;
    if (p.F < 0 && p.S <= 0)
        return 3;
    if (p.F >= 0 && p.S < 0)
        return 4;
    return 0;
}

auto angle_sort = [](pll p1, pll p2)
{
    int q1 = quad(p1), q2 = quad(p2);
    if (q1 != q2)
        return q1 < q2;
    return p1.S * p2.F < p2.S * p1.F; };