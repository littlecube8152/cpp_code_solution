#include <algorithm>
#include <iostream>
using namespace std;

struct cat
{
    string name;
    int job;
    int age;
};

bool compare(cat c1, cat c2)
{
    if (c1.job < c2.job)
        return 1;
    if (c1.job > c2.job)
        return 0;
    if (c1.job == 4)
    {
        if (c1.age < c2.age)
            return 1;
        if (c1.age > c2.age)
            return 0;
    }
    if (c1.age < c2.age)
        return 0;
    if (c1.age > c2.age)
        return 1;
    return c1.name < c2.name;
}
int c, food;
cat array[10001];

int main()
{
    while (cin >> c >> food)
    {
        for (int i = 0; i < c; i++)
        {
            string tmp;
            cin >> array[i].name >> tmp >> array[i].age;
            if (tmp == "elder")
                array[i].job = 0;
            if (tmp == "nursy")
                array[i].job = 1;
            if (tmp == "kit")
                array[i].job = 2;
            if (tmp == "warrior")
                array[i].job = 3;
            if (tmp == "appentice")
                array[i].job = 4;
            if (tmp == "medicent")
                array[i].job = 5;
            if (tmp == "deputy")
                array[i].job = 6;
            if (tmp == "leader")
                array[i].job = 7;
        }
        sort(array, array + c, compare);
        for (int i = 0; i < min(food, c); i++)
        {
            cout << array[i].name << '\n';
        }
    }
}