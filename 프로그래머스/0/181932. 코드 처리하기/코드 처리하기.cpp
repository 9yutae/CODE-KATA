#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool flag = false;
    
    for(int i=0;i<code.length();i++) {
        int cur = code[i];
        if(code[i]=='1') flag = !flag;
        else if(flag && i%2) answer.push_back(cur);
        else if(!(flag || i%2)) answer.push_back(cur);
    }
    
    if(!answer.empty()) return answer;
    return "EMPTY";
}