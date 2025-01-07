#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), std::greater<>());
    for(int i=m-1;i<score.size();) {
        answer = answer + score[i]*m;
        i += m;
    }
    
    return answer;
}