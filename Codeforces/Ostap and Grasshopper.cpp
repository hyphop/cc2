#include <iostream>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <stdio.h>

int main()
{
    
#ifdef __APPLE__  
    freopen("in.in", "r", stdin);
#endif
    
    int n, k;
    std::cin >> n >> k;
    
    char line[n]; int src, target;
    for (int i = 0; i < n; i++) {
        std::cin >> line[i];
        if (line[i] == 'G') src= i;
        else if (line[i] == 'T') target = i;
    }
    
    bool visited[n];
    std::fill(visited, visited + n, false);
    
    std::queue<int> q;
    q.push(src);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        assert(0 <= x && x < n);
        if (visited[x] || line[x] == '#')
            continue;
        
        visited[x] = true;
        
        if (x == target) {
            std::cout << "YES\n";
            return 0;
        }
        if (x >= k) q.push(x - k);
        if (x < (n - k)) q.push(x + k);
    }
    
    std::cout << "NO\n";
    
}