#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> stats;
vector<bool> selected;
int minDiff = 0xffffff;

void calculateMinDiff() {
    vector<int> teamA, teamB;
    for (int i = 0; i < N; i++) {
        if (selected[i]) teamA.push_back(i);
        else teamB.push_back(i);
    }

    int sumA = 0, sumB = 0;
    for (int i = 0; i < N/2; i++) {
        for (int j = i + 1; j < N/2; j++) {
            sumA += stats[teamA[i]][teamA[j]] + stats[teamA[j]][teamA[i]];
            sumB += stats[teamB[i]][teamB[j]] + stats[teamB[j]][teamB[i]];
        }
    }

    minDiff = min(minDiff, abs(sumA - sumB));
    return;
}

void backtrack(int idx, int depth) {
    if (depth == N / 2) {
        calculateMinDiff();
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            backtrack(i + 1, depth + 1);
            selected[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    stats.assign(N, vector<int>(N));
    selected.assign(N, false);

    for (auto& row : stats) {
        for (int& x : row)
            cin >> x;
    }

    selected[0] = true;
    backtrack(1, 1);

    cout << minDiff;
    return 0;
}
