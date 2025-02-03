#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {    
    map<string, int> types;
    for(const auto& w:clothes) {
        types[w[1]]++;
    }
    
    int answer = 1;
    for(const auto& w:types) {
        answer *= (w.second + 1);
    }
    
    return answer - 1;
}