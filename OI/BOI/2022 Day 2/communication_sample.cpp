#include"communication.h"
//
// --- Sample implementation for the task communication ---
//
// To compile this program with the sample grader, place:
//     communication.h communication_sample.cpp sample_grader.cpp
// in a single folder, then open the terminal in this directory (right-click onto an empty spot in the directory,
// left click on "Open in terminal") and enter e.g.:
//     g++ -std=c++17 communication_sample.cpp sample_grader.cpp
// in this folder. This will create a file a.out in the current directory which you can execute from the terminal
// as ./a.out
// See task statement or sample_grader.cpp for the input specification
//
void encode(int N, int X) {
    send(1);
    send(0);
    send(1);
    send(1);
}

std::pair<int, int> decode(int N) {
    receive();
    receive();
    receive();
    return {1337, 42};
}