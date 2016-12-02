#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{

    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
        int x, y, c; cin >> x >> y >> c;
        long long sol = 0;
        for (int i = 1; i <= sqrt(c); i++) {
            if (c % i == 0) {
                int l = i, r = c / i;
                if (l <= x && r <= y)
                    sol++;
                if (l <= y && r <= x && (l != r))
                    sol++;
            }
        }
        cout << sol << "\n";
    }
}