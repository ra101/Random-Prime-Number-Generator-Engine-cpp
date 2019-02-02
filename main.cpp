#include "prime.h"
#include <sstream>          //complete std:stringstream
#include <iostream>         
#include <chrono>           //for timeStamp
#include <random>           //random_prime_engine takes std::random engins as input template

int main()
{
    ra::random_prime_engine<std::default_random_engine> rpe1;

    std::chrono::steady_clock::time_point timeStamp = std::chrono::steady_clock::now();
    unsigned long rand_sedd = ((std::chrono::duration_cast<std::chrono::nanoseconds>(timeStamp.time_since_epoch()).count()));
    ra::random_prime_engine<std::default_random_engine> rpe2(rand_sedd);

    std::stringstream state;
    state<<rpe1; //save current state


    std::cout<<"\nfrom rpe1 (without seed): ";
    for(int i=0;i<10;i++)
    {
        std::cout<<rpe1()<<", ";
    }

    std::cout<<"\nfrom rpe2 (with timestamp as seed): ";
    for(int i=0;i<10;i++)
    {
        std::cout<<rpe2()<<", ";
    }

    state>>rpe1; //restore old state
    std::cout<<"\nfrom rpe1 (without seed) again: ";
    for(int i=0;i<10;i++)
    {
        std::cout<<rpe1()<<", ";
    }

    std::cout<<"\nMin of any rpe: "<<rpe1.min();
    std::cout<<"\nMax of any rpe: "<<rpe1.max();
}
