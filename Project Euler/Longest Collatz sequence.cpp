#include <iostream>
#include <map>

const int NMAX = 1000000;

unsigned int lengthOfChain(unsigned long long n)
{
    unsigned int cnt = 0;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    unsigned int max = 1;
    unsigned long long maxnum = 1;
    for (unsigned long long i = 1; i <= NMAX; i++) {
        unsigned int cur = lengthOfChain(i);
        if (cur > max) {
            max = cur;
            maxnum = i;
        }  
    }
    std::cout << maxnum << std::endl;
}

