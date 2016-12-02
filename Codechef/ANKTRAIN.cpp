#include <iostream>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        int type = N % 8;
        switch (type) {
            case 0: std::cout << N - 1 << "SL\n"; break;
            case 1: std::cout << N + 3 << "LB\n"; break;
            case 2: std::cout << N + 3 << "MB\n"; break;
            case 3: std::cout << N + 3 << "UB\n"; break;
            case 4: std::cout << N - 3 << "LB\n"; break;
            case 5: std::cout << N - 3 << "MB\n"; break;
            case 6: std::cout << N - 3 << "UB\n"; break;
            case 7: std::cout << N + 1 << "SU\n"; break;
        }
    }
}