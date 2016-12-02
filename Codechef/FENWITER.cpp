#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

int bitcount(string x)
{
	int cnt = 0;
	for (int i = 0; i < x.length(); i++) 
		if (x[i] == '1') cnt++;
	return cnt;
}

string succ(string x)
{
	assert(bitcount(x) != x.length());
	
	for (int i = x.length() - 1; i >= 0; i--) {
		if (x[i] == '0') {
			x[i] = '1';
			break;
		} else {
			x[i] = '0';
		}
	}
	return x;
}

int main()
{
	#ifdef __APPLE__
		freopen("in.in", "r", stdin);
	#endif


	int T; cin >> T;
	while (T--) {
		string a, b, c; int n; 
		cin >> a >> b >> c >> n;
		if (bitcount(c) != c.length()) {
			cout << bitcount(a) + n * bitcount(b) + bitcount(succ(c)) << "\n";
		} else {
			if (bitcount(b) != b.length()) {
				cout << bitcount(a) + (n - 1) * bitcount(b) + bitcount(succ(b)) << "\n";
			} else {
				if (bitcount(a) != a.length()) {
					cout << bitcount(succ(a)) << "\n";
				}
				else
					cout << "1\n";
			}
		}
	}
	
}