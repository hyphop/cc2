#ifdef JUDGE
#include <fstream>
std::ifstream cin("aplusb.in");
std::ofstream cout("aplusb.out");
#endif

int main()
{   
    
    #ifdef __APPLE__
        freopen("in.in", "r", stdin);
    #endif
    
    int A, B;
    std::cin >> A >> B;
    std::cout << A + B << std::endl;
}