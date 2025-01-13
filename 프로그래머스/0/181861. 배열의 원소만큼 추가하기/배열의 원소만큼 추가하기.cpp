#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(const auto w:arr) {
        int rept = w;
        while(rept--) {
            answer.push_back(w);
        }
    }
    return answer;
}