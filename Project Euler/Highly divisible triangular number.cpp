#include <iostream>
#include <cmath>

const int N = 500;

int getTriangularNumber(int x)
{
    return x * (x + 1) / 2;
}

int countDivisors(int n)
{
    int s = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i * i == n)
                s += 1;
            else 
                s += 2;
        } 
    }
    return s;
}

int main()
{
    int n = 1;
    while (countDivisors(getTriangularNumber(n)) < N) {
        n++;
    }
    std::cout << getTriangularNumber(n) << std::endl;
    return 0;
}