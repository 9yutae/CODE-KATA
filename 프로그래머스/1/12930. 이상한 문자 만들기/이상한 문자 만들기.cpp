#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    for(int i=0, space=0;i<s.size();i++) {
        if(s[i] == ' ') space = i+1;
        else if((i-space)%2 == 0 && islower(s[i])) s[i] -= 32;
        else if((i-space)%2 && isupper(s[i])) s[i] += 32;
    }
    
    return s;
}