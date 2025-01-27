#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++) {
        bool isAnswer = true;
        stack<char> bracket;
        for(int j=i;j<s.size();j++) {
            if(s[j] == '(' || s[j] == '[' || s[j] == '{')
                bracket.push(s[j]);
            else if(s[j] == ')') {
                if(bracket.top() != '(') isAnswer = false;
                else bracket.pop();
            }
            else if(s[j] == ']') {
                if(bracket.top() != '[') isAnswer = false;
                else bracket.pop();
            }
            else if(s[j] == '}') {
                if(bracket.top() != '{') isAnswer = false;
                else bracket.pop();
            }
            if(!isAnswer) break;
        }
        for(int j=0;j<i;j++) {
            if(s[j] == '(' || s[j] == '[' || s[j] == '{')
                bracket.push(s[j]);
            else if(s[j] == ')') {
                if(bracket.top() != '(') isAnswer = false;
                else bracket.pop();
            }
            else if(s[j] == ']') {
                if(bracket.top() != '[') isAnswer = false;
                else bracket.pop();
            }
            else if(s[j] == '}') {
                if(bracket.top() != '{') isAnswer = false;
                else bracket.pop();
            }
            if(!isAnswer) break;
        }
        
        if(isAnswer && bracket.empty()) answer++;
    }
    
    return answer;
}