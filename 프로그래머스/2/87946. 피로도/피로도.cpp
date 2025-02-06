#include <string>
#include <vector>

using namespace std;

void dfs(int cnt, int k, vector<vector<int>> &dungeons, vector<bool>& visited, int& maxCount) {
    maxCount = max(maxCount, cnt);
    
    for(int i=0;i<dungeons.size();i++) {
        if(!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(cnt + 1, k - dungeons[i][1], dungeons, visited, maxCount);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int maxCount = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(0, k, dungeons, visited, maxCount);
    
    return maxCount;
}