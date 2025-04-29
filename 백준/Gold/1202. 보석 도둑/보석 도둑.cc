#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewelry(N);
    for (auto& p : jewelry) {
        cin >> p.first >> p.second;
    }
    sort(jewelry.begin(), jewelry.end());

    vector<int> backpack(K, 0);
    for (auto& w : backpack) {
        cin >> w;
    }
    sort(backpack.begin(), backpack.end());

    priority_queue<int> pq;
    int jewelryIdx = 0;
    long long answer = 0;
    for (int bagIdx = 0; bagIdx < K; ++bagIdx) {
        while (jewelryIdx < N && jewelry[jewelryIdx].first <= backpack[bagIdx]) {
            pq.push(jewelry[jewelryIdx].second);
            ++jewelryIdx;
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << endl;
}
