// http://codeforces.com/contest/719/problem/C

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

    int N, T; cin >> N >> T;
    int pre;
    vector<int> suf; bool dot = false;

    for (int i = 0; i < N; i++) {
        char c; 
        cin >> c; int dig = c - '0';
        if (c == '.')
            dot = true;
        else if (!dot)
            pre = pre * 10 + dig;
        else 
            suf.push_back(dig);
    }

    for (int i = 0; i < suf.size(); i++)
        cout << suf[i] << "\n";
    int sl = suf.size();
    int hops[100000] = {0};
    bool worth[10000] = {false}; 
    hops[sl - 1] = 0;

    worth[sl - 1] = suf[sl - 1] >= 5;

    for (int i = sl - 2; i != 0; i--) {
        if (suf[i + 1] >= 5) {
            hops[i] = 1;
            worth[i] = true;
        }
        else if (worth[i + 1])
            hops[i] = hops[i + 1] + 1;
        else 
            hops[i] = 0;
    }

    for (int i = 0; i < sl; i++)
        cout << hops[i] << "\n";
}