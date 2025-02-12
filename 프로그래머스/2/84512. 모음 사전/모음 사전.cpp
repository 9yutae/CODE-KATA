#include <string>
#include <vector>

using namespace std;
string vowels = "AEIOU";

bool dfs(string compare, string word, int& answer) {
    if(compare.size() == 5) return false;
    
    for(const auto& w:vowels) {
        answer++;
        if(compare + w == word) return true;
        if(dfs(compare + w, word, answer)) return true;
    }
    
     return false;
}

int solution(string word) {
    int answer= 0;
    string compare = "";
    dfs(compare, word, answer);

    return answer;
}