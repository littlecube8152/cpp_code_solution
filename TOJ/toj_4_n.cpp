#include <algorithm>
#include <iostream>
using namespace std;

string XOR(string a, string b)
{
    string c;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            c += "0";
        }
        else
        {
            c += "1";
        }
    }
    return c;
}

string arcXOR(string statment, string b)
{
    string c;
    for (int i = 0; i < statment.length(); i++)
    {
        if (statment[i] == '0')
        {
            c += b[i];
        }
        else if (b[i] == '1')
        {
            c += "0";
        }
        else
        {
            c += "1";
        }
    }
    return c;
}

int main()
{
    int input, length;
    int count;
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        cin >> count >> length;
        string I[count], O[count], SW[count];
        int bits = 100;
        for (int j = 0; j < count; j++)
        {
            cin >> I[j];
        }
        for (int j = 0; j < count; j++)
        {
            cin >> O[j];
        }
        sort(I, I + count);
        for (int j = 0; j < count; j++)
        {
            SW[j] = XOR(I[0], O[j]);
        }
        for (int j = 0; j < count; j++)
        {
            string xor_O[count];
            for (int k = 0; k < count; k++)
            {
                xor_O[k] = arcXOR(SW[j], O[k]);
            }
            sort(xor_O, xor_O + count);
            bool possible = true;
            for (int k = 0; k < count; k++)
            {
                if (xor_O[k] != I[k])
                {
                    possible = false;
                    break;
                }
            }
            if (possible == true)
            {
                int result = 0;
                for (int k = 0; k < SW[j].length(); k++)
                {
                    if (SW[j][k] == '1')result ++;
                }
                if (result < bits)
                {

                    bits = result;
                }
            }
        }
        if (bits == 100)
        {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        }
        else
        {
            cout << "Case #" << i << ": " << bits << '\n';
        }
    }
}