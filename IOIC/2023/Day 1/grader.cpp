#include "walking.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>

const int MAX_CHARACTERS = 48763;
int main() {
	int N, M;	
	std::cin >> N >> M;	
	assert(N > 0 && M >= N - 1);

	std::vector<int> U(M, 0), V(M, 0);
	std::vector<std::vector<int> >  G(N+1, std::vector<int>());
	for (int i = 0;i < M;i++) {
		std::cin >> U[i] >> V[i];
		assert(1 <= U[i] && U[i] <= N && 1 <= V[i] && V[i] <= N);
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
	}

	int B;
	std::cin >> B;	
	assert(1 <= B && B <= N);
	int A;
	std::cin >> A;
	assert(1 <= A && A <= N);

	std::string S = Danbing(N, M, U, V, B);	
	std::cout << "String sent by Danb: " << S << std::endl;	
	std::cout << "Total characters: " << S.size() << std::endl;
	if (S.size() > MAX_CHARACTERS) {
		std::cout << "Wrong Answer: Too many characters" << std::endl;
		exit(0);
	}

	Ziskinit(S);

	int steps = 0;
	while (A != B && steps < N){
		int nxt = Zisking(N, G[A]);		
		std::cout << "Zisking(" << A << "): " << nxt << std::endl;
		if (std::find(G[A].begin(), G[A].end(), nxt) == G[A].end()) {
			std::cout << "Wrong Answer: Invalid return value" << std::endl;
			exit(0);
		}
		A = nxt;
		steps++;
	}
	if (A == B) {
		std::cout << "Found, distance = " << steps << std::endl;
	} else {
		std::cout << "Wrong Answer: Haven't found B after N steps" << std::endl;
	}
	
}
