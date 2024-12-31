#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    for(auto& w:s) {
        if(w == ' ') continue;
        else if(isupper(w)) {
            w = (w + n - 'A') % 26 + 'A';
        }
        else w = (w + n - 'a') % 26 + 'a';
    }
    
    return s;
}