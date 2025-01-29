#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(const auto w:citations) {
        if(w > answer) answer++;
        else return answer;
    }
    
    return answer;
}