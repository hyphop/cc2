#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <assert.h>

int main()
{
    
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
    
    int N, X, Y;
    std::cin >> N >> X >> Y;
    
    std::vector<std::pair<int, int> > exam_times;
    for (int i = 0; i < N; i++) {
        int L, R; std::cin >> L >> R;
        exam_times.push_back(std::make_pair(L, R));
    }
    
    std::vector<int> en;
    std::vector<int> ex;
    
    for (int i = 0; i < X; i++) {
        int t; std::cin >> t;
        en.push_back(t);
    }
    
    for (int i = 0; i < Y; i++) {
        int t; std::cin >> t;
        ex.push_back(t);
    }
    
    std::sort(en.begin(), en.end());
    std::sort(ex.begin(), ex.end());
    
    int best = INT_MAX;
    for (int i = 0; i < N; i++) {
        int l = std::lower_bound(en.begin(), en.end(), exam_times[i].first) - en.begin();
        int r = std::lower_bound(ex.begin(), ex.end(), exam_times[i].second) - ex.begin();
        // std::cout << l << " " << r << std::endl;
        if ((en[l] == exam_times[i].first || l != 0) && r != Y) {
            if (en[l] == exam_times[i].first)
                best = std::min(best, ex[r] - en[l] + 1);
            else
                best = std::min(best, ex[r] - en[l - 1] + 1);
        }
    }
  
    std::cout << best << std::endl;
        
}