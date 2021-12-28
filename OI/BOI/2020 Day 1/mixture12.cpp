#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define ll long long
using namespace std;

struct Vector
{
    long long x, y, z;
    Vector(ll x, ll y, ll z) : x(x), y(y), z(z){};
    Vector() : x(0), y(0), z(0){};
};

struct Plane
{
    long long a, b, c;
    Plane(ll a, ll b, ll c) : a(a), b(b), c(c){};
    Plane() : a(0), b(0), c(0){};
};

Vector vectorPlus(Vector v1, Vector v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

int planeSide(Vector v, Plane p);

Plane twoVector(Vector v1, Vector v2)
{
    //assert(planeSide(v1, p1) == 0);
    //assert(planeSide(v2, p1) == 0);
    Plane p1 = Plane(-(v1.z * v2.y - v2.z * v1.y) * (v1.y * v2.z - v2.y * v1.z),
                     (v1.z * v2.x - v2.z * v1.x) * (v1.y * v2.z - v2.y * v1.z),
                     (v1.z * v2.y - v2.z * v1.y) * (v1.y * v2.x - v2.y * v1.x));
    if (p1.a == 0 && p1.b == 0 && p1.c == 0)
    {
        p1 = twoVector(Vector(v1.z, v1.x, v1.y), Vector(v2.z, v2.x, v2.y));
        swap(p1.a, p1.b);
        swap(p1.b, p1.c);
    }
    ll gcd = __gcd(p1.a, __gcd(p1.b, p1.c));
    p1.a /= gcd;
    p1.b /= gcd;
    p1.c /= gcd;

    return p1;
}


Vector planeToVector(Plane p1)
{
    return Vector(p1.a, p1.b, p1.c);
}

bool isZero(Vector v1)
{
    if (v1.x == 0 && v1.y == 0 && v1.z == 0)
        return true;
    return false;
}

int planeSide(Vector v, Plane p)
{
    if (p.a * v.x + p.b * v.y + p.c * v.z > 0)
        return 1;
    if (p.a * v.x + p.b * v.y + p.c * v.z == 0)
        return 0;
    return -1;
}

bool sameVector(Vector v1, Vector v2)
{
    if (v1.x * v2.y == v1.y * v2.x &&
        v1.z * v2.y == v1.y * v2.z &&
        v1.x * v2.z == v1.z * v2.x)
        return true;
    return false;
}

int N;
Vector perfect, mixture[505];

int check(int mx)
{
    for (int i = 1; i <= mx; i++)
        if (!isZero(mixture[i]))
            if (sameVector(mixture[i], perfect))
                return 1;
    for (int i = 1; i <= mx; i++)
        if (!isZero(mixture[i]))
            for (int j = i + 1; j <= mx; j++)
                if (!isZero(mixture[j]))
                    if (!sameVector(mixture[i], mixture[j]))
                    {
                        Plane p1 = twoVector(mixture[i], mixture[j]), p2, p3;
                        Vector v3 = planeToVector(p1);
                        p2 = twoVector(v3, mixture[i]);
                        p3 = twoVector(v3, mixture[j]);
                        Vector sample = vectorPlus(mixture[i], mixture[j]);

                        if (planeSide(perfect, p1) == 0)
                        {
                            //cout << "on plane :D\n";
                            if (planeSide(sample, p2) * planeSide(perfect, p2) >= 0 &&
                                planeSide(sample, p3) * planeSide(perfect, p3) >= 0)
                                return 2;
                        }
                    }
    for (int i = 1; i <= mx; i++)
        if (!isZero(mixture[i]))
            for (int j = i + 1; j <= mx; j++)
                if (!isZero(mixture[j]))
                    for (int k = j + 1; k <= mx; k++)
                        if (!isZero(mixture[k]))
                            if (!sameVector(mixture[i], mixture[j]) &&
                                !sameVector(mixture[i], mixture[k]) &&
                                !sameVector(mixture[k], mixture[j]))
                            {
                                Plane p1 = twoVector(mixture[i], mixture[j]),
                                      p2 = twoVector(mixture[i], mixture[k]),
                                      p3 = twoVector(mixture[j], mixture[k]);
                                if (planeSide(mixture[k], p1) != 0)
                                    if (planeSide(mixture[k], p1) * planeSide(perfect, p1) >= 0 &&
                                        planeSide(mixture[j], p2) * planeSide(perfect, p2) >= 0 &&
                                        planeSide(mixture[i], p3) * planeSide(perfect, p3) >= 0)
                                    {
                                        //cout << i << " " << j << " " << k << "\n";
                                        return 3;
                                    }
                            }
    return 0;
}

signed main()
{
   // Plane test = twoVector(Vector(0, 0, 10), Vector(1, 0, 9));
   // cout << test.a << " " << test.b << " " << test.c << '\n';
    ll x, y, z;
    cin >> x >> y >> z;
    perfect = Vector(x, y, z);
    cin >> N;
    for (int i = 1, j = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            cin >> x >> y >> z;
            mixture[j] = Vector(x, y, z);
            j++;
        }
        else
        {
            cin >> x;
            mixture[x] = Vector();
        }

        cout << check(j) << '\n';
    }
}
