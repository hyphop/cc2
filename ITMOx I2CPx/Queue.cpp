#ifdef JUDGE
#include <fstream>
std::ifstream cin("queue.in");
std::ofstream cout("queue.out");
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

const int NMAX = 1000000;

class queue {
    int backing[NMAX];
    int front, back, min, mincount, size;
public:
    queue() {
        front = back = size = 0;
    }
    void push(int x) {
        backing[back++] = x;
        size++;
        if (size == 1) {
            min = x;
            mincount = 1;
        }
    }
    
    int pop() {
        size--;
        int ret = backing[front++];
        if ()
    }
};

int main()
{
    int N;
    cin >> N;
    queue q;
    for (int i = 0; i < N; i++) {
        char op; cin >> op;
        if (op == '+') {
            int x; cin >> x;
            q.push(x);
        } else if (op == '-') {
            cout << q.pop() << '\n';
        }
    }
}