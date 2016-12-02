#include <iostream>
#include <string>

std::string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string elevens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

std::string repr(int n)
{
    if (n < 10)
        return ones[n];
    if (n < 100 && n % 10 == 0)
        return tens[n / 10 - 1];
    if (n < 20)
        return elevens[n - 11];
    if (n < 100)
        return tens[(n - n % 10) / 10 - 1] + " " + ones[n % 10];
    if (n < 1000 && n % 100 == 0)
        return ones[n / 100] + " hundred";
    if (n < 1000)
        return ones[n / 100] + " hundred and " + repr(n % 100);
    return "one thousand"; 
}

bool pred(char c)
{
    return std::isalpha(c);
}

int countChars(std::string s)
{
    return std::count_if(s.begin(), s.end(), pred);
}

int main()
{
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        // std::cout << repr(i) << std::endl;
        sum += countChars(repr(i));
    }
    std::cout << sum << std::endl;
    
    return 0;
}