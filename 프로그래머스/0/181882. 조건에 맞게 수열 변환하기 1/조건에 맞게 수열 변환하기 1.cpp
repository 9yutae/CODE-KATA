#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(auto& w:arr) {
        if(w >= 50 && w%2 == 0) w/=2;
        else if(w < 50 && w%2 == 1) w*=2;
        answer.emplace_back(w);
    }
    return answer;
}