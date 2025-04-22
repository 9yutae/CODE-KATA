#include <string>
#include <vector>

using namespace std;

vector<int> apeach, lion, answer;
int MaxDiff;

void dfs(int depth, int n, int apeachScore, int lionScore) {
    if (depth == 11) { 
        if (apeachScore >= lionScore) return;
        lion[10] += n;
        if (lionScore - apeachScore > MaxDiff) {
            answer = lion;
            MaxDiff = lionScore - apeachScore;
        }
        else if (lionScore - apeachScore == MaxDiff) {
            for(int i=10; i>0; i--) {
                if (lion[i] > answer[i]) {
                    answer = lion;
                    break;
                }
                else if (lion[i] < answer[i])
                    break;
            }
        }
        return;
    }
    
    int minArrowCnt = apeach[depth] + 1;
    if (minArrowCnt <= n) {
        int nextApeachScore = apeachScore;
        int nextLionScore = lionScore + (10 - depth);
        if (minArrowCnt > 1) nextApeachScore -= (10 - depth);
        
        lion.push_back(minArrowCnt);
        dfs(depth + 1, n - minArrowCnt, nextApeachScore, nextLionScore);
        lion.pop_back();
    }
    
    lion.push_back(0);
    dfs(depth + 1, n, apeachScore, lionScore);
    lion.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    
    int apeachScore = 0;
    for (int i=0; i<info.size(); i++) {
        if (info[i]) apeachScore += (10 - i);
    }
    
    dfs(0, n, apeachScore, 0);
    
    if (MaxDiff == 0) return { -1 };
    return answer;
}