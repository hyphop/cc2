#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

map<pair<int, int>, int> memo;

int solve(int arr[], int N, int b)
{
	// feeding the b'th knight is mandatory
	
	auto t = memo.find(make_pair(N, b));
	if (t != memo.end()) {
		return t->second;
	}
	if (N < 2) {
		if (N == 1 && b == 0)
			return arr[0] + arr[1];
		else if (N == 0 && b == 1)
			return arr[0] + arr[1];
		else
			return arr[N];
	} else {
		int f = arr[N] + min(solve(arr, N - 1, b), solve(arr, N - 2, b));
		memo[make_pair(N, b)] = f;
		return f;
	}
}

int main()
{
	#ifdef __APPLE__
		freopen("in.in", "r", stdin);
	#endif
		
	int N; cin >> N;
	int arr[N];
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	if (N == 1)
		cout << "0\n";
	else if (N == 2)
		cout << min(arr[0], arr[1]) << "\n";
	else {
		cout << min(solve(arr, N - 1, -1), solve(arr, N - 2, 0)) << "\n";
	}
}