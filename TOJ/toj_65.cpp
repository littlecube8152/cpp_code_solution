#include <iostream>
#include <chrono>
#include <random>
using namespace std;
int main()
{
    random_device rd;
    // seed value is designed specifically to make initialization
    // parameters of std::mt19937 (instance of std::mersenne_twister_engine<>)
    // different across executions of application
    mt19937::result_type seed = rd() ^ (
            (mt19937::result_type)
            chrono::duration_cast<chrono::seconds>(
                chrono::system_clock::now().time_since_epoch()
                ).count() +
            (mt19937::result_type)
            chrono::duration_cast<chrono::microseconds>(
                chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    mt19937 gen(seed);

    /* ^^^Yes. Generating single pseudo-random number makes no sense
       even if you use std::mersenne_twister_engine instead of rand()
       and even when your seed quality is much better than time(NULL) */    
        mt19937::result_type n;
         while( ( n = gen() ) > mt19937::max() -
                                    ( mt19937::max() - 2 )%2 ){}
        // reject readings that would make n%6 non-uniformly distributed

        cout << n % 2 << '\n';
    }