#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> evidence(2, 0);
int minValue = 0xffffff;

void backtrack(int depth, const vector<vector<int>>& info, const int& n, const int& m) {
    if (depth == info.size()) {
        minValue = min(minValue, evidence[0]);
        return;
    }
    
    if (evidence[0] > minValue) return;

    if (info[depth][1] + evidence[1] < m) {
        evidence[1] += info[depth][1];
        backtrack(depth + 1, info, n, m);
        evidence[1] -= info[depth][1];
    }
    
    if (info[depth][0] + evidence[0] < n) {
        evidence[0] += info[depth][0];
        backtrack(depth + 1, info, n, m);
        evidence[0] -= info[depth][0];
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    sort(info.begin(), info.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] > rhs[0];
    });
    backtrack(0, info, n, m);
    return minValue != 0xffffff ? minValue : -1;
}