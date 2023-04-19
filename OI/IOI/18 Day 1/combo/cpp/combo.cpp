#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int N) {
  string S = "";
  char c[3];
  if(press("AB"))
  {
    if(press("A"))
      S = "A", c[0] = 'B', c[1] = 'X', c[2] = 'Y';
    else
      S = "B", c[0] = 'A', c[1] = 'X', c[2] = 'Y';
  }
  else
  {
    if(press("X"))
      S = "X", c[0] = 'A', c[1] = 'B', c[2] = 'Y';
    else
      S = "Y", c[0] = 'A', c[1] = 'B', c[2] = 'X';
  }
  if(N == 1)
    return S;

  for (int i = 2; i < N; i++)
  {
    int diff = press(S + c[1] + S + c[2] + c[0] + S + c[2] + c[1] + S + c[2] + c[2]) - (int)S.size();
    S += c[diff];
  }
  if(press(S + c[0] + S + c[1]) == N)
  {
    if(press(S + c[0]) == N)
      S += c[0];
    else
      S += c[1];
  }
  else
    S += c[2];
  return S;
}
