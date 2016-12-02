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

    int N, K;
    cin >> N >> K;

    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < K) arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    long long sol = 0;
    for (int i = 0; i < arr.size(); i++) {
        sol += upper_bound(arr.begin(), arr.end(), K - arr[i] - 1) - arr.begin();
        if (arr[i] <= K - arr[i] - 1)
            sol--;
    }

    cout << sol / 2 << "\n";

}