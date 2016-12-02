// http://codeforces.com/contest/719/problem/0

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

    int N; cin >> N; int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    if (arr[N - 1] == 15)
        cout << "DOWN\n";
    else if (arr[N - 1] == 0)
        cout << "UP\n";
    else if (N == 1)
        cout << "-1\n";
    else if (arr[N - 1] > arr[N - 2])
        cout << "UP\n";
    else
        cout << "DOWN\n";

}