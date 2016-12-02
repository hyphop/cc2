#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{

    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
        double s, v; cin >> s >> v;
        cout << fixed << setprecision(6) << 2.0 / 3.0 * s / v << endl;
    }
}