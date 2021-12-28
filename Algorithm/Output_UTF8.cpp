#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    cout << "UTF-8 喔喔喔喔喔喔";
}
