#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

const int inf = INT_MAX;
const int NMAX = 500;

int main()
{
    
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
    
    int N, M;
    std::cin >> N >> M;
    
    bool safe[NMAX + 1][NMAX + 1] = {};
    int dp[N + 1][N + 1];
    int grid[N + 1][N + 1];
  
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        int X, Y, range;
        std::cin >> X >> Y >> range;
        for (int j = std::max(X - range, 1); j <= std::min(X + range, N); j++) {
            for (int k = std::max(Y - range, 1); k <= std::min(Y + range, N); k++) {
                int dx = std::abs(X - j);
                int dy = std::abs(Y - k);
                if ((dx + dy) <= range)
                    safe[j][k] = true;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
             
            if (!safe[i][j]) {
                dp[i][j] = -inf;
                continue;
            } 
            
            int best = -inf;
            if (i > 1) best = std::max(best, dp[i - 1][j]);
            if (j > 1) best = std::max(best, dp[i][j - 1]);
            
            if (i == 1 && j == 1)
                dp[i][j] = grid[i][j];
            else if (best != -inf)
                dp[i][j] = grid[i][j] + best;
            else
                dp[i][j] = -inf;
            
        }
    }
        
    if (dp[N][N] == -inf)
        std::cout << "NO" << std::endl;
    else {
        std::cout << "YES" << std::endl << dp[N][N] << std::endl;
    }
    
    
}