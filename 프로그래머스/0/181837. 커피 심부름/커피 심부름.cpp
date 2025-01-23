#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for(const auto& w:order) {
        if(w.find("cafelatte") != string::npos) answer += 5000;
        else answer += 4500;
    }
    return answer;
}