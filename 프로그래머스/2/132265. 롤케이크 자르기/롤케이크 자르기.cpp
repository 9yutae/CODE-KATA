#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> lhs;
    map<int, int> rhs;
    for(const auto& w:topping) {
        rhs[w]++;
    }
    
    int answer=0;
    for(const auto& w:topping) {
        lhs[w]++;
        rhs[w]--;
        
        if(rhs[w] == 0) rhs.erase(w);
        if(lhs.size() == rhs.size()) answer++;
    }
    
    return answer;
}