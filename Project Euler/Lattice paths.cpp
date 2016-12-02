#include <iostream>

int main()
{
    long long DP[21][21];
    DP[0][0] = 1;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            if (i == 0 && j == 0) continue;
            DP[i][j] = 0;
            if (i - 1 >= 0) DP[i][j] += DP[i - 1][j];
            if (j - 1 >= 0) DP[i][j] += DP[i][j - 1];
        }
    }
    std::cout << DP[20][20] << std::endl;
}