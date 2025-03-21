#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> stats) {
    vector<int> team(n, 1);
    for(int i=0; i<n/2; i++) team[i] = 0;

    int answer = 0xfffff;
    do {
        vector<int> teamA, teamB;
        for (int i=0; i<n; i++) {
            if(team[i] == 0) teamA.push_back(i);
            else teamB.push_back(i);
        }

        int sumA = 0, sumB = 0;
        for (int i=0; i<teamA.size(); i++) {
            for (int j=i+1; j<teamA.size(); j++) {
                sumA += (stats[teamA[i]][teamA[j]] + stats[teamA[j]][teamA[i]]);
                sumB += (stats[teamB[i]][teamB[j]] + stats[teamB[j]][teamB[i]]);
            }
        }

        int diff = sumA > sumB ? sumA - sumB : sumB - sumA;
        answer = min(answer, diff);

    } while(next_permutation(team.begin(), team.end()));

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> stats(N, vector<int>(N, 0));
    for (auto& vec : stats) {
        for (auto& w : vec) {
            cin >> w;
        }
    }

    cout << solution(N, stats);

    return 0;
}
