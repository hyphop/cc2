#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int len = s.length();
        char out[len]; bool f = true;

        for (int i = 0; i < len / 2; i++) {
            int ref = len - i - 1;
            if (s[i] == '.' && s[ref] == '.')
                out[i] = 'a';
            else if (s[i] == '.')
                out[i] = s[ref];
            else if (s[ref] == '.')
                out[i] = s[i];
            else if (s[i] == s[ref])
                out[i] = s[i];
            else {
                cout << "-1\n";
                f = false;
                break;
            }
            out[ref] = out[i];
        }

        if (!f) continue;

        if (len % 2 == 1) {
            if (s[len / 2] == '.')
                out[len / 2] = 'a';
            else
                out[len / 2] = s[len / 2];
        }

        cout << string(out, len) << endl;
    }
}
