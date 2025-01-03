#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    map<char, int> m;
    vector<int> answer;
    for(int i=0;i<s.size();i++) {
        if(m.find(s[i]) != m.end()) answer.emplace_back(i-m[s[i]]);
        else answer.emplace_back(-1);
        m[s[i]] = i;        
    }
    
    return answer;
}