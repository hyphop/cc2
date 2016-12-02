#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int c0 = 0, c1 = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            (s[i] == '1') ? c1++ : c0++;
        }
        if (c0 == 1 || c1 == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
  }
}
