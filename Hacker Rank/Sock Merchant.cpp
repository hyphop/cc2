#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{

    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif

    int n; cin >> n;
    int counts[100]; fill(counts, counts + 100, 0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        counts[x - 1]++;
    }

    int sol = 0;
    for (int i = 0; i < 100; i++) {
        sol += counts[i] / 2;
    }

    cout << sol << "\n";
}