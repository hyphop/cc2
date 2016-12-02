#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1005;

int flag = true;
int colour[NMAX];

void dfs_explore(int source, int col, vector<int> adj[NMAX])
{
    colour[source] = col;
    for (int i = 0; i < (int) adj[source].size(); i++) {
        int v = adj[source][i];
        if (colour[v] == -1) { // unexplored
            dfs_explore(v, col ^ 1, adj);
        } else {
            if (colour[v] != (col ^ 1)) {
                flag = false;
                break;
            }
        }
    }
}

void dfs(int V, vector<int> adj[NMAX])
{
    for (int i = 0; i < V && flag; i++) {
        if (colour[i] == -1) {
            dfs_explore(i, 0, adj);
        }
    }
}

void print(int V, vector<int> *adj)
{
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < (int) adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}

vector<int> complement(int N, vector<int> vec, int ex)
{
    bool lookup[N]; fill(lookup, lookup + N, false);
    for (int i = 0; i < (int) vec.size(); i++) {
        int x = vec[i];
        lookup[x] = true;
    }
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        if (!lookup[i] && i != ex)
            ret.push_back(i);
    }
    return ret;
}

void printColouring(int V)
{
    for (int i = 0; i < V; i++) {
        cout << i << ": " << colour[i] << "\n";
    }
}

void init()
{
    fill(colour, colour + NMAX, -1);
    flag = true;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        init();
        int N, M; cin >> N >> M;
        vector<int> adj[NMAX];
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < NMAX; i++) {
            adj[i] = complement(N, adj[i], i);
        }
        // print(N, adj);

        dfs(N, adj);
        if (flag) {
            cout << "YES\n";
            // printColouring(N);
        }
        else
            cout << "NO\n";

    }
}
