#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string myString, string pat) {
    for(auto& w:myString) w = tolower(w);
    for(auto& w:pat) w = tolower(w);
    
    if(myString.size() < pat.size()) return 0;
    for(int i=0; i <= myString.size() - pat.size(); i++) {
        if(myString.substr(i, pat.size()) == pat) return 1;
    }
    
    return 0;
}