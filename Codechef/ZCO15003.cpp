#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.second != b.second) {
        return a.second <= b.second;
    } else {
        return a.second <= b.second;
    }
}

int main()
{
    
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
    
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int> > ranges;
    
    for (int i = 0; i < N; i++) {
        int L, R; std::cin >> L >> R;
        ranges.push_back(std::make_pair(L, R));
    }
    
    std::sort(ranges.begin(), ranges.end(), cmp);
    
    int solution = 0, cur = -1;
    for (int i = 0; i < N; i++) {
        if (ranges[i].first > cur) {
            solution++;
            cur = ranges[i].second;
        }
    }
    
    std::cout << solution << std::endl;
    
}