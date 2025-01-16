#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for(const auto& w:num_str) answer += w - '0';
    return answer;
}