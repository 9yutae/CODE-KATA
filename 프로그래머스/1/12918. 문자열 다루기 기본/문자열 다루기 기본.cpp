#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() == 4 || s.size() == 6) {
        for(const auto& w:s) {
            if(isdigit(w) == 0) answer = false; 
        }    
    }
    else answer = false;
    
    return answer;
}