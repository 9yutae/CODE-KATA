#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if(num_list.size() > 10) {
        for(const auto& w:num_list) answer += w;
    }
    else {
        answer = 1;
        for(const auto& w:num_list) answer *= w;
    }
    return answer;
}