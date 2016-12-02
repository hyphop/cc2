#include <iostream>

int main()
{
    int T; std::cin >> T;
    while (T--) {
        std::string s; std::cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '>') s[i] = '<';
            else if (s[i] == '<') s [i] = '>';
        }
        int sol = 0;
        for (int i = 0; i < len; i++) {
           if (s[i] == '<' && i != 0 && s[i - 1] == '>')  sol++;
           if (s[i] == '>' && i != (s.length() - 1) && s[i + 1] == '<') sol++;
       }
       std::cout << sol / 2 << "\n";
    }
}


