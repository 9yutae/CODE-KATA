#include <string>
#include <vector>

using namespace std;

vector<int> apeach, lion, answer;
int MaxDiff;    // 최대 점수 차이 저장

// DFS 함수
void dfs(int depth, int n, int apeachScore, int lionScore) {
    if (depth == 11) { // 모든 점수/(10~0점)에 대해 판단이 끝났을 때
        if (apeachScore >= lionScore) return;   // 라이언이 이기지 못한 경우 무시
        lion[10] += n;  // 남은 화살 0ㅈ머에 몰아주기
        
        // 점수 차이가 최대일 경우 결과 갱신
        if (lionScore - apeachScore > MaxDiff) {
            answer = lion;
            MaxDiff = lionScore - apeachScore;
        }
        // 점수 차이가 같으면 낮은 점수에 더 많이 쏜 경우 선택
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
    
    // 해당 타겟 점수를 이기기 위해 필요한 최소 화살 개수
    int minArrowCnt = apeach[depth] + 1;
    
    // 해당 점수에 화살을 쏘는 경우
    if (minArrowCnt <= n) {
        int nextApeachScore = apeachScore;
        int nextLionScore = lionScore + (10 - depth);
        // 어피치가 점수를 가지고 있던 경우
        if (apeach[depth] > 0) nextApeachScore -= (10 - depth);
        
        lion.push_back(minArrowCnt);
        dfs(depth + 1, n - minArrowCnt, nextApeachScore, nextLionScore);
        lion.pop_back();
    }
    
    // 해당 점수에 화살을 쏘지 않는 경우
    lion.push_back(0);
    dfs(depth + 1, n, apeachScore, lionScore);
    lion.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    
    // 어피치 초기 점수 계산
    int apeachScore = 0;
    for (int i=0; i<info.size(); i++) {
        if (info[i]) apeachScore += (10 - i);
    }
    
    dfs(0, n, apeachScore, 0);  // DFS 시작
    
    if (MaxDiff == 0) return { -1 };    // 이길 수 없는 경우
    return answer;
}