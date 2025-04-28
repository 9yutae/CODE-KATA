#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<vector<int>> starts = {{ -startX, startY }, { 2*m - startX, startY},
                                  { startX, -startY }, { startX, 2*n - startY}};
    
    vector<int> answer;
    for (const auto ball : balls) {
        int minDist = 0xffffff;
        for (int i=0; i<4; i++) {
            // 좌우 반사일 때 (i == 0 || i == 1)
            if (startY == ball[1] && ((i == 0 && startX > ball[0]) || (i == 1 && startX < ball[0]))) {
                continue; // 스킵
            }
            // 상하 반사일 때 (i == 2 || i == 3)
            if (startX == ball[0] && ((i == 2 && startY > ball[1]) || (i == 3 && startY < ball[1]))) {
                continue; // 스킵
            }
            
            int distance = pow(ball[0] - starts[i][0], 2) + pow(ball[1] - starts[i][1], 2);
            minDist = min(minDist, distance);
        }
        answer.push_back(minDist);
    }
    
    return answer;
}