#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer {7, 7};
    int correct = 0, zeros = 0;
    for(const auto& w:lottos) {
        if(w!=0) {
            auto iter = find(win_nums.begin(), win_nums.end(), w);
            if(iter != win_nums.end()) correct++;
        }
        else zeros++;
    }
    
    answer[0] -= (correct + zeros != 0 ? correct + zeros : zeros + 1);
    answer[1] -= (correct != 0 ? correct : 1);
    
    return answer;
}