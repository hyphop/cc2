#include <algorithm>
#include <iostream>
#include <fstream>

#define INT_CONST 200

struct LargeInt {
    short digits[INT_CONST];
    int len;
};

LargeInt * loadInts(int n)
{
    LargeInt *ret = (LargeInt *) malloc(sizeof(LargeInt) * n);
    std::fstream fin("in.in");
    for (int i = 0; i < n; i++) {
        std::string s; fin >> s; int cnt = 0; 
        for (int j = s.length() - 1; j >= 0; j--) {
            ret[i].digits[cnt++] = s[j] - '0';
        }
        ret[i].len = cnt;
    }
    fin.close();
    return ret;
}

void printLargeInt(LargeInt l) 
{
    for (int i = l.len - 1; i >= 0; i--) {
        std::cout << l.digits[i];
    }
    std::cout << std::endl;
}

LargeInt addLargeInts(LargeInt a, LargeInt b)
{
    LargeInt res;
    int maxlen = std::max(a.len, b.len);
    int carry = 0; int i;
    for (i = 0; i < maxlen; i++) {
        int adig = (i > a.len) ? 0 : a.digits[i];
        int bdig = (i > b.len) ? 0 : b.digits[i];
        int s = adig + bdig + carry;
        if (s >= 10) {
            carry = s / 10;
            s %= 10;
        } else {
            carry = 0;
        }
        res.digits[i] = s;
    }
    if (carry != 0) 
        res.digits[i++] = carry;
    res.len = i;
    return res;
}

int main()
{
    LargeInt *arr = loadInts(100);
    LargeInt sum = arr[0];
    for (int i = 1; i < 100; i++) {
        sum = addLargeInts(sum, arr[i]);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << sum.digits[sum.len - 1 - i];
    }
    std::cout << std::endl;
    
    return 0;
}