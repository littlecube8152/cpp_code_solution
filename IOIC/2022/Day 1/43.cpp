#include <cstdio>

using namespace std;

int main()
{
    printf("3 2000\n");
    for (int i = 1000; i >= 1; i--)
        printf("1 2 %d\n", i);
    for (int i = 1000; i >= 1; i--)
        printf("2 3 %d\n", i);
}