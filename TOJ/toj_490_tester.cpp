#include <iostream>
using namespace std;

int line[10000000];

void spray(long long int locate, long long int id){
    for (int i = 0; i < locate; i++)
        line[i] = id;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int count, game;
    cin >> count;
    for (long long int i = 0; i < count; i++)
        cin >> line[i];
    cin >> game;
    for (long long int i = 0; i < game; i++){
        long long int locate, id;
        cin >> locate >> id;
        spray(locate, id);
    }
    for (long long int i = 0; i < count; i++)
        cout << line[i] << " ";
    cout << '\n';
}
