#ifdef JUDGE
#include <fstream>
std::ifstream cin("stack.in");
std::ofstream cout("stack.out");
#elif defined(__APPLE__)
#include <iostream>
#include <fstream>
std::ifstream cin("in.in");
using std::cout;
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <vector>
const int NMAX = 1000005;
int backing[NMAX];

int main()
{
    int N;
    cin >> N;
   
    int idx = 0;
    for (int i = 0; i < N; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int x; cin >> x;
            backing[idx++] = x;
        } else if (op == '-') {
            cout << backing[--idx] << '\n';
        }
    }
}



