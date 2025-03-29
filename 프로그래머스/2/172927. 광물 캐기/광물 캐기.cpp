#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int minFatigue = 0xffffff;

void dfs(int idx, vector<int>& picks, vector<string>& minerals, int currentFatigue, int maxDepth, int depth) {
    if (depth == maxDepth || idx >= minerals.size()) {
        minFatigue = min(minFatigue, currentFatigue);
        return;
    }
    
    for(int i=0; i < 3; i++) {
        if (picks[i] == 0) continue;
        
        int localFatigue = 0;
        int nextIdx = idx;
        
        for(int j=0; j < 5 && nextIdx < minerals.size(); j++, nextIdx++) {
            if (minerals[nextIdx] == "diamond") localFatigue += pow(5, i);
            else if (minerals[nextIdx] == "iron") localFatigue += (i < 2 ? 1 : 5);
            else localFatigue++;
        }

        picks[i]--;
        dfs(nextIdx, picks, minerals, currentFatigue + localFatigue, maxDepth, depth + 1);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int maxDepth = min((int)ceil(minerals.size() / 5.0), accumulate(picks.begin(), picks.end(), 0));
    dfs(0, picks, minerals, 0, maxDepth, 0);    
    return minFatigue;
}