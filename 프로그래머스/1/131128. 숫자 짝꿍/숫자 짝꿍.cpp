#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {    
    vector<int> Xvec(10, 0), Yvec(10, 0);
    for(const auto& w:X) Xvec[w-'0']++;
    for(const auto& w:Y) Yvec[w-'0']++;
    
    vector<int> commonVec(10, 0);
    bool flag = false;
    for(int i=0;i<10;i++) {
        commonVec[i] = min(Xvec[i], Yvec[i]);
        if(commonVec[i] != 0) flag = true;
    }
    
    if(!flag) return "-1";
    
    string answer;
    for(int i=9;i>=0;i--) {
        while(commonVec[i]--) {
            answer += i + '0';
        }
    }
    if(answer[0] == '0') answer = "0";
    
    return answer;
}