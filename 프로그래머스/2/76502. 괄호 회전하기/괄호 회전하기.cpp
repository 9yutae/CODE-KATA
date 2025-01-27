#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++) {
        string temp = s.substr(i) + s.substr(0,i);
        bool isAnswer = true;
        stack<char> bracket;
        
        for(int j=0;j<temp.size();j++) {
            if(!isAnswer) break;
            
            if(temp[j] == '(' || temp[j] == '[' || temp[j] == '{')
                bracket.push(temp[j]);
            else if(bracket.empty()) isAnswer = false;
            else if(temp[j] == ')') {
                if(bracket.top() != '(') isAnswer = false;
                else bracket.pop();
            }
            else if(temp[j] == ']') {
                if(bracket.top() != '[') isAnswer = false;
                else bracket.pop();
            }
            else if(temp[j] == '}') {
                if(bracket.top() != '{') isAnswer = false;
                else bracket.pop();
            }
        }
        
        if(isAnswer && bracket.empty()) answer++;
    }
    
    return answer;
}