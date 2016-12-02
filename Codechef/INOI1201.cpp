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
    int N; 
    cin >> N;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back(make_pair(x + y, t));
    }
    sort(v.begin(), v.end(), greater<pair<int, int> >());
    int sol = 0, c = 0;
    for (int i = 0; i < N; i++) {
        // cout << v[i].first << " " << v[i].second << "\n";
        c += v[i].second;
        sol = max(sol, c + v[i].first);
    }
    cout << sol << "\n";
}