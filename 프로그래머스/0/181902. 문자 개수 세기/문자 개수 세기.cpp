#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for(auto& w:my_string) {
        if(isupper(w)) answer[w-'A']++;
        else answer[w-'a'+26]++;
    }
    
    return answer;
}