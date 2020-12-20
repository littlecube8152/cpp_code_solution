#include <bits/stdc++.h>
#define ll long long
#define c 0.3137254902
using namespace std;

int main(){
    int en, mat, sci;
    cin >> en >> mat >> sci;
    double pointa;
    pointa = 1.25 * en + 2.0 * mat + sci * 1.0;
    pointa *= c;
    double p, q;
    cin >> p >> q;
    double pointb;
    pointb = p + q;
    pointb *= 0.4;
    double point;
    point = pointa + pointb;
    double low;
    cin >> low;
    if(point>=low){
        cout << "YA\n";
    }else{
        cout << "QQ\n";
    }

    return 0;
}