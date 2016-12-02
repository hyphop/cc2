#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <cassert>
 
using namespace std;
 
int intersect(vector<int> a, vector<int> b)
{
    // precondition: a, b are sorted

    if (a.size() > b.size())
        return intersect(b, a);
    else {
        int idx = 0, cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            for (; idx < b.size(); ) {
                if (b[idx] > a[i])
                    break;
                else if (b[idx] == a[i]) {
                    cnt++; idx++;
                    break;                
                } else
                    idx++;
            }
        }
        return cnt;
    }
}

int noob_intersection(vector<int> a, vector<int> b) 
{
    vector<int> res;
    res.resize(a.size() + b.size());
    vector<int>::iterator it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), res.begin());
    res.resize(it - res.begin());
    return res.size();

}

int main()
{
 
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
 
    int N, K;
    cin >> N >> K;
 
    vector<vector<int> > arr;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        for (int j = 0; j < t; j++) {
            int num; cin >> num;
            arr[i].push_back(num);
        }
        sort(arr[i].begin(), arr[i].end());
    }
 
    queue<int> q;
    q.push(0);
 
    bool isRelative[N];
    fill(isRelative, isRelative + N, false);
    int size = 1;
 
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 1; i < N; i++) {
 
            if (isRelative[i] || i == t) 
                continue;
 
            int common = intersect(arr[t], arr[i]);
            // assert(common == noob_intersection(arr[t], arr[i]));
 
            if (common >= K) {
                isRelative[i] = true;
                size += 1;
                q.push(i);
            }
        }
    }
 
    cout << size << "\n";
}
 