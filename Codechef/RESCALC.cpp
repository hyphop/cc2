#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int max_score = INT_MIN;
        int max_score_idx = -1;
        bool tied = false;
        for (int i = 0; i < N; i++) {
            int num_cookies; cin >> num_cookies;
            int cnt[6]; fill(cnt, cnt + 6, 0);

            for (int j = 0; j < num_cookies; j++) {
                int type; cin >> type;
                cnt[type - 1]++;
            }

            vector<int> counts = vector<int>(cnt, cnt + 6);
            sort(counts.begin(), counts.end());

            int score = num_cookies;
            score += 4 * counts[0];
            score += 2 * (counts[1] - counts[0]);
            score += 1 * (counts[2] - counts[1]);

            // cerr << "Score of " << i << " " << score << "\n";
            if (score > max_score) {
                max_score = score;
                max_score_idx = i;
                tied = false;
            } else if (score == max_score) {
                tied = true;
            }
        }
        if (tied)
            cout << "tie\n";
        else if (max_score_idx == 0)
            cout << "chef\n";
        else
            cout << max_score_idx + 1 << "\n";
    }
}
