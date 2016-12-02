#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct p {
    int v, d;
    p(int a, int b) {
        v = a;
        d = b;
    }
    bool operator<(const p& cur) const {
        return d > cur.d;
    } 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int C, F;
    cin >>  C >> F;
    vector<vector<pair<int, int> > > adj;
    adj.resize(C + 1);

    for (int i = 0; i < F; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        adj[x].push_back(make_pair(y, p));
        adj[y].push_back(make_pair(x, p));
    }
    
    int highest = 0;
    

    for (int S = 1; S <= C; S++) {

        vector<int> distances(C + 1);
        fill(distances.begin(), distances.end(), -1);
        priority_queue<p> pq;
        pq.push(p(S, 0));
        
        while (!pq.empty()) {
            p top = pq.top();
            pq.pop();
            int v = top.v, dist = top.d;
            if (distances[v] == -1) {
                distances[v] = dist;
                if (dist > highest)
                    highest = dist;
                for (int k = 0; k < adj[v].size(); k++) {
                    pair<int, int> temp = adj[v][k];
                    pq.push(p(temp.first, dist + temp.second));
                }
            }
        }
    }

    cout << highest << "\n";


}