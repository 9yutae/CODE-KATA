#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0, i=0;
    for(const auto& w:absolutes) {
        answer += w * (signs[i++] ? 1 : -1);
    }
    
    return answer;
}