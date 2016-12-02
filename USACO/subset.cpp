/*
ID: rishav.1
LANG: C++11
TASK: subset
*/

#include <iostream>

using namespace std;

long long dp[400][50];

int f(int a, int b)
{
    long long cnt;
    // fprintf(stdout, "Invoked f(%d, %d).\n", a, b);

    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    else if (a == 0 || a == b) {
        cnt = 1;
    }
    else if (b > a) {
        cnt = 0;
    } else {
        cnt = 0;
        for (int k = 1; k < b; k++) {
            cnt += f(a - b, k);
        }
    }
    dp[a][b] = cnt;
    return cnt;
}

long long g(int a, int b)
{
    long long cnt = 0;
    for (int i = 1; i <= min(a, b); i++)
        cnt += f(a, i);
    return cnt;
}

void init()
{
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 50; j++)
            dp[i][j] = -1;
    }
}

int main()
{
    init();

    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    int N; cin >> N;
    int prod = N * (N + 1);
    if (prod % 4 != 0) {
        cout << "0\n";
        return 0;
    }
    cout << g(prod / 4, N) / 2 << "\n";
}
