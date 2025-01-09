#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    auto idx = myString.find(pat);
    answer = myString.substr(0, idx + pat.size());
    
    while(myString.find(pat, idx+1) != string::npos) {
        idx = myString.find(pat, idx+1);
        answer = myString.substr(0, idx + pat.size());
    }
    
    return answer;
}