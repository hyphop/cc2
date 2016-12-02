// http://codeforces.com/contest/719/problem/B

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int f1(int len, string s)
{
    int wb = 0, wr = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 && s[i] == 'b')
            wb += 1;
        else if (i % 2 == 1 && s[i] == 'r')
            wr += 1;
    }
    int lesser = min(wb, wr);
    return lesser + max(wb, wr) - lesser;
}

int f2(int len, string s)
{
     int wb = 0, wr = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 && s[i] == 'r')
            wr += 1;
        else if (i % 2 == 1 && s[i] == 'b')
            wb += 1;
    }
    int lesser = min(wb, wr);
    return lesser + max(wb, wr) - lesser;
}
 
int main()
{

    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif

    int N; cin >> N;
    string str; cin >> str;

    cout << min(f1(N, str), f2(N, str)) << "\n";
}