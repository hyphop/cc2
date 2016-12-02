#include <iostream>

int main()
{
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
 
    int T; std::cin >> T;
    for (int t = 0; t < T; t++) {
        int K;
        std::cin >> K;
        std::cout >> (K + 1) / 2 - 1 << std::endl;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K)
        }
    }
}