#include <algorithm>
#include <math.h>
#include <iostream>
#include <set>
#include <vector>

const int NMAX = 1e6+5;

bool primes[NMAX];
std::vector<int> primelist;

int even[NMAX];
int odd[NMAX];

std::set<int> used_primes;

void sieve()
{
    std::fill(primes, primes + NMAX, true);
    for (int i = 2; i <= (int) sqrt(NMAX); i++) {
        if (primes[i]) {
           for (int j = i * i; j < NMAX; j += i) {
              primes[j] = false;
           }
        }
    } 
    for (int i = 2; i < NMAX; i++) {
        if (primes[i]) {
            primelist.push_back(i);
        }
    }
}

int main()
{

    sieve();

    int T;
    std::cin >> T;


    while (T--) {

        std::fill(even, even + NMAX, 0);
        std::fill(odd, odd + NMAX, 0);
        used_primes.clear();

        int N; std::cin >> N;
        for (int i = 0; i < N; i++) {
            int ai; std::cin >> ai;
            for (int j = 0; j < primelist.size(); j++) {
                int cur = primelist[j];
                if (cur > ai) break;
                if (ai % (cur * cur) == 0)
                    even[cur]++;
                else if (ai % cur == 0)
                    odd[cur]++;
                if (ai % cur == 0)
                    used_primes.insert(cur);
            }
        }

        int sol = 0;
        for (int prime : used_primes) {
            // std::cout << prime << " ";
            int diff = N - (even[prime] + odd[prime]);
            sol += std::min(even[prime] + diff, odd[prime]);
        }

        std::cout << sol << "\n";
    }
}
      

