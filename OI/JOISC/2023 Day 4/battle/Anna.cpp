#include "Anna.h"
#include <bits/stdc++.h>
using namespace std;

void Anna(int X, int Y, int N, string S) {
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i != X && j != Y) {
				Paint(i, j, S[0] == 'A');
			}
		}
	}
}
