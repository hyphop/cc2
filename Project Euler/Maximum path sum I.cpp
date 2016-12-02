#include <iostream>
#include <fstream>
#include <vector>

const int NROWS = 15;

std::vector<std::vector<int> > loadGrid(int nrows)
{
    std::fstream fin("in.in");
    std::vector<std::vector<int> > grid;
    grid.resize(nrows);
    for (int i = 0; i < nrows; i++) {
        grid[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            fin >> grid[i][j];
        }
    }
    fin.close();
    return grid;
}

int solve(std::vector<std::vector<int> > grid, int nrows)
{
    int DP[nrows][nrows];
    DP[0][0] = grid[0][0];
    for (int i = 1; i < nrows; i++) {
        for (int j = 0; j <= i; j++) {
            DP[i][j] = -1;
            if (i != j) DP[i][j] = std::max(DP[i][j], DP[i - 1][j]);
            if (j != 0) DP[i][j] = std::max(DP[i][j], DP[i - 1][j - 1]);
            DP[i][j] += grid[i][j];
        }
    }
    int best = -1;
    for (int i = 0; i < nrows; i++) {
        if (DP[nrows - 1][i] > best)
            best = DP[nrows- 1][i];
    }
    return best;
}

int main()
{
    std::cout << solve(loadGrid(NROWS), NROWS) << std::endl;
}