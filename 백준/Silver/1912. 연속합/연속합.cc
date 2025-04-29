#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n, 0);
    for (auto& w : vec) {
        cin >> w;
    }

    vector<int> dp(n+1, 0);
    int answer = - 1001;
    for (int i=1; i<=n; i++) {
        dp[i] = max(dp[i-1] + vec[i-1], vec[i-1]);
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
}
