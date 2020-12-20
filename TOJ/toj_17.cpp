#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    string str[26] = {"A",
                      "ABA",
                      "ABCBA",
                      "ABCDCBA",
                      "ABCDEDCBA",
                      "ABCDEFEDCBA",
                      "ABCDEFGFEDCBA",
                      "ABCDEFGHGFEDCBA",
                      "ABCDEFGHIHGFEDCBA",
                      "ABCDEFGHIJIHGFEDCBA",
                      "ABCDEFGHIJKJIHGFEDCBA",
                      "ABCDEFGHIJKLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA",
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA"};
    for (int i = 0; i < a; i++)
    {
        cout << string(a - i - 1, ' ') << str[i] << '\n';
    }
    for (int i = a - 2; i >= 0; i--)
    {
        cout << string(a - i - 1, ' ') << str[i] << '\n';
    }
    for (int i = 0; i < b; i++)
    {
        cout << string(a - i - 1, ' ') << str[i] << '\n';
    }
    for (int i = b - 2; i >= 0; i--)
    {
        cout << string(a - i - 1, ' ') << str[i] << '\n';
    }
}