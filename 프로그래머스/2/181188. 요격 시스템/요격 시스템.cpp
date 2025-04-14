#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());
    
    int xRange = 0;
    int answer = 0;
    for (int i=0; i<targets.size(); i++) {
        if (targets[i][0] >= xRange) {
            xRange = targets[i][1];
            answer++;
        }
        else {
            xRange = min(xRange, targets[i][1]);
        }
    }
    
    return answer;
}