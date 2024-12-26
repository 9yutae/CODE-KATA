#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(const auto& w:arr) {
        if(w%divisor == 0) answer.emplace_back(w);
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.emplace_back(-1);
    
    return answer;
}