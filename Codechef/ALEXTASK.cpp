#include <iostream>
#include <limits.h>

long long hcf(long long a, long long b)
{
    if (a > b)
        return hcf(b, a);
    else {
        if (a == 0)
            return b;
        else
            return hcf(b % a, a);
    }
}

long long lcm(long long a, long long b)
{
    return a * b / hcf(a, b);
}

int main()
{
    
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
    
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        long long arr[N];
        
        for (int i = 0; i < N; i++)
            std::cin >> arr[i];
        
        long long solution = LLONG_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long long cur = lcm(arr[i], arr[j]);
                if (cur < solution)
                    solution = cur;
            }
        }   
        std::cout << solution << std::endl; 
    }
}