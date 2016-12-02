#include <iostream>
#include <math.h>

bool isprime(int n)
{
    bool prime = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    int n;
    std::cin >> n;
    // std::cout  << INT_MAX << std::endl;

   
    if (isprime(n)) {
        std::cout << "1\n";
        return 0;
    }
    
    if (n % 2 == 0) {
        std::cout << "2\n";
        return 0;
    }
    
    if (n >= 4 && isprime(n - 2)) {
        // splitting as 2 + x
        std::cout << "2\n";
        return 0;
    }
  
    std::cout << "3\n";
}