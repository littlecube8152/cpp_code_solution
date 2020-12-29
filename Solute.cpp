#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

map<pair<int, int>, int> ans_data;
vector<string> cation = {"Hg₂²⁺", "Cu⁺", "Pb²⁺", "Ag⁺", "Tl⁺", "Ca²⁺", "Sr²⁺", "Ba²⁺"};
vector<string> anion = {"I⁻", "Br⁻", "Cl⁻"};
int answer;

void init()
{
    
}
void problem_gen(int mode)
{

    switch (mode)
    {
    case 0:

        break;
    }
}

int main()
{
    int mode = 0;
    cout << "Mode Select [0] Solubility\n";
    cin >> mode;
    init();
    problem_gen(mode);
}