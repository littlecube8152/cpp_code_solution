#include "chameleon.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

namespace {

using std::cerr;
using std::exit;
using std::fprintf;
using std::printf;
using std::scanf;

constexpr int Q_MAX = 20'000;
constexpr int N_MAX = 500;

int N;
int Y[N_MAX * 2 + 1], C[N_MAX * 2 + 1], L[N_MAX * 2 + 1];

int query_count = 0;
int answer_count = 0;
bool finishes[N_MAX * 2 + 1];

void WrongAnswer(int code) {
  printf("Wrong Answer [%d]\n", code);
  exit(0);
}

}  // namespace

int Query(const std::vector<int> &p) {
  //cerr << "Query: ";
  //for(auto i : p)
  //	  cerr << i << ' ';
  //cerr << " = ";
  if (++query_count > Q_MAX) WrongAnswer(3);
  bool presents[N_MAX * 2 + 1];
  for (int i = 1; i <= N * 2; ++i) presents[i] = false;
  for (const int k : p) {
    if (k <= 0 || k > N * 2) WrongAnswer(1);
    if (presents[k]) WrongAnswer(2);
    presents[k] = true;
  }
  bool colors[N_MAX + 1];
  for (int j = 1; j <= N; ++j) colors[j] = false;
  int color_count = 0;
  for (int i = 1; i <= N * 2; ++i) {
    if (!presents[i]) continue;
    const int color = presents[L[i]] ? C[L[i]] : C[i];
    if (!colors[color]) {
      ++color_count;
      colors[color] = true;
    }
  }
  //cerr << color_count << '\n';
  return color_count;
}

void Answer(int a, int b) {
  ++answer_count;
  if (a <= 0 || a > N * 2) WrongAnswer(4);
  if (b <= 0 || b > N * 2) WrongAnswer(4);
  if (finishes[a]) WrongAnswer(5);
  finishes[a] = true;
  if (finishes[b]) WrongAnswer(5);
  finishes[b] = true;
  if (C[a] != C[b]) WrongAnswer(6);
}

int main() {
  
 if (scanf("%d", &N) != 1) {
    fprintf(stderr, "Error while reading input.\n");
    exit(1);
  }
  for (int i = 1; i <= N * 2; ++i) {
   /*if (scanf("%d", &Y[i]) != 1) {
      fprintf(stderr, "Error while reading input.\n");
      exit(1);
    }*/
	Y[i] = (i <= N ? 0 : 1);
  }
  for (int i = 1; i <= N * 2; ++i) {
    /*if (scanf("%d", &C[i]) != 1) {
      fprintf(stderr, "Error while reading input.\n");
      exit(1);
    }*/
	C[i] = (i + 1) / 2;
  }
  for (int i = 1; i <= N * 2; ++i) {
    /*if (scanf("%d", &L[i]) != 1) {
      fprintf(stderr, "Error while reading input.\n");
      exit(1);
    }*/
	L[i] = (i + 1) % (2 * N) + 1;
  }  
  for (int i = 1; i <= N * 2; ++i) finishes[i] = false;
  Solve(N);
  if (answer_count != N) WrongAnswer(7);
  printf("Accepted: %d\n", query_count);
  return 0;
}