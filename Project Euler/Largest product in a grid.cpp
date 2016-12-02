#include <iostream>
#include <fstream>
#include <climits>
#include <cassert>

const int N = 20;

void loadGrid(int grid[N][N])
{
    std::fstream fin("in.in");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) 
            fin >> grid[i][j];
    }
    fin.close();
}

int solveDiagR(int grid[N][N])
{
    int best; bool first = true;
    for (int i = 0; i <= N - 4; i++) {
        for (int j = 0; j <= N - 4; j++) {
            int sum = 1;
            for (int k = 0; k < 4; k++) {
                sum *= grid[i + k][j + k];
            }
            if (first) {
                best = sum;
                first = false;
            }
            else if (sum > best)
                best = sum;
        }
    }
    return best;
}

int solveDiagL(int grid[N][N])
{
    int best; bool first = true;
    for (int i = 0; i <= N - 4; i++) {
        for (int j = 3; j < N; j++) {
            int sum = 1; 
            for (int k = 0; k < 4; k++) {
                sum *= grid[i + k][j - k];
            }
            if (first) {
                best = sum;
                first = false;
            }
            else if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

int solveVert(int grid[N][N])
{
    int best; bool first = true;
    for (int i = 0; i <= N - 4; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 1;
            for (int k = 0; k < 4; k++)
                sum *= grid[i + k][j];
            if (first) {
                best = sum;
                first = false;
            }
            else if (sum > best)
                best = sum;
        }
    }
    return best;
}

int solveHoriz(int grid[N][N])
{
    int best; bool first = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - 4; j++) {
            int sum = 1;
            for (int k = 0; k < 4; k++) {
                sum *= grid[i][j + k];
            }
            if (first) {
                best = sum;
                first = false;
            }
            else if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

int solve(int grid[N][N]) {
    return std::max(solveDiagL(grid),
           std::max(solveDiagR(grid),
           std::max(solveHoriz(grid),
                    solveVert(grid))));
}

int main()
{
    int grid[N][N];
    loadGrid(grid);
    std::cout << solve(grid) << std::endl;
    
    return 0;
}

