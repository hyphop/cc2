#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int gt(vector<int> *v, int n)
{
	return lower_bound(v->begin(), v->end(), n) - v->begin();
}

int gteq(vector<int> *v, int n)
{
	return upper_bound(v->begin(), v->end(), n) - v->begin();
}

int main()
{
	#ifdef __APPLE__
		freopen("in.in", "r", stdin);
	#endif
˜		
	int N, K;
	cin >> N >> K;
	
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end());
	
	long long sol = 0;
	for (int i = 0; i < arr.size(); i++) {
		sol += arr.size() - gt(&arr, arr[i] + K);
		sol += gteq(&arr, arr[i] - K);

	}
	cout << sol / 2 << "\n";	
}