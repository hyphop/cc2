#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	#ifdef __APPLE__
		freopen("in.in", "r", stdin);
	#endif
	
	int N; cin >> N;
	vector<int> arr;
	arr.resize(N);
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (N <= 2)
		cout << "0\n";
	else {
		vector<int> dp; dp.resize(N);
		for (int i = 0; i < N; i++) {
			if (i < 3)
				dp[i] = arr[i];
			else 
				dp[i] = arr[i] + min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
		}
		
		int sol = dp[N - 3];
		for (int i = N - 3; i < N; i++) 
			sol = min(sol, dp[i]);
		cout << sol << "\n";
	}
		
}