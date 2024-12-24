#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l;i<=r;i++) {
        string str = to_string(i);
        bool flag = true;
        for(const auto& w:str) {
            if(w!='0' && w!='5') {
                flag = false;
                break;
            }
        }
        
        if(flag) answer.emplace_back(i);
    }
    
    if(answer.empty()) answer.emplace_back(-1);
    
    return answer;
}