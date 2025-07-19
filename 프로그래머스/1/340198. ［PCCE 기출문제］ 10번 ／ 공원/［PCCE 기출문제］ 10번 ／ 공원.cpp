#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DP(const vector<vector<string>>& park) {
    int row = park.size();
    int col = park[0].size();
    int maxSize = 0;
    
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < row ; i++) {
        for (int j = 0; j < col; j++) {
            if (park[i][j] != "-1") dp[i+1][j+1] = 0;
            else dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
            maxSize = max(maxSize, dp[i+1][j+1]);
        }
    }
    
    return maxSize;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<int>());
    int MAX = DP(park);
    for (const auto& w : mats) {
        if (w <= MAX) return w;
    }
    
    return -1;
}