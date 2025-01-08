#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1, paintedFrom = section[0];
    for(const auto& w:section) {
        if(w >= paintedFrom + m) {
            paintedFrom = w;
            answer++;
        }
    }
    return answer;
}