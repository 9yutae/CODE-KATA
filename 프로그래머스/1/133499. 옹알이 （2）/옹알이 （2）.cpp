#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(const auto& w:babbling) {
        bool flag = true;
        int curr = -1, prev = -1;
        for(int i=0;i<w.size();i++) {
            if(w.substr(i,3)=="aya") { i += 2; curr = 0; }
            else if(w.substr(i,2) == "ye") { i += 1; curr = 1; }
            else if(w.substr(i,3) == "woo") { i += 2; curr = 2; }
            else if(w.substr(i,2) == "ma") { i += 1; curr = 3; }
            else {
                flag = false;
                break;
            }
            
            if(curr==prev) {
                flag = false;
                break;
            }
            else prev = curr;
        }
        if(flag) answer++;
    }
    
    return answer;
}