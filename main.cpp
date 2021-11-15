#include "prime.h"

#include <iostream>
#include <sstream> //complete std:stringstream
#include <chrono>  //for timeStamp
#include <random>  //random_prime_engine takes std::random engins as input template

int main()
{
    ra::random_prime_engine<std::default_random_engine> rpe_1;

    std::chrono::steady_clock::time_point timeStamp = std::chrono::steady_clock::now();
    unsigned long rand_seed = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStamp.time_since_epoch()).count();
    ra::random_prime_engine<std::default_random_engine> rpe_2(rand_seed);

    std::stringstream state;
    state << rpe_1; //save current state

    std::cout << "\nfrom rpe_1 (without seed): ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << rpe_1() << ", ";
    }

    std::cout << "\nfrom rpe_2 (with timestamp as seed): ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << rpe_2() << ", ";
    }

    state >> rpe_1; //restore old state
    std::cout << "\nfrom rpe_1 (without seed) again: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << rpe_1() << ", ";
    }

    std::cout << "\nMin of any rpe: " << rpe_1.min();
    std::cout << "\nMax of any rpe: " << rpe_1.max();
}
