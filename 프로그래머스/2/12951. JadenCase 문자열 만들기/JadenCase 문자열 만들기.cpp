#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool isNextSpace = true;
    
    for(int i=0;i<s.size();i++) {
        if(s[i] == ' ') isNextSpace = true;
        else if(isNextSpace && islower(s[i])) {
            s[i] -= 32;
            isNextSpace = false;
        }
        else if(!isNextSpace && isupper(s[i])) {
            s[i] += 32;
            isNextSpace = false;
        }
        else isNextSpace = false;
    }    
    
    return s;
}
