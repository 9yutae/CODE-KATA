#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<=t.size() - p.size();i++) {
        string subt = t.substr(i, p.size());
        if(stoll(subt) <= stoll(p)) answer++;
    }
    
    return answer;
}