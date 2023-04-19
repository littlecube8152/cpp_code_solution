#include <cstdio>

int main()
{
    printf("3 142\\n");
    for (short i = 71; i >= 1; --i)
        printf("1 2 %hd\\n", i);
    for (short i = 71; i >= 1; --i)
        printf("2 3 %hd\\n", i);
}