#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++) {
        int same = 1, diff = 0;
        if(i == s.size()-1) {
            answer++;
            break;
        }
        
        for(int j=i+1;j<s.size();j++) {            
            s[j] == s[i] ? same++ : diff++;
            if(same == diff || j == s.size()-1) {
                answer++;
                i = j;
                break;
            }
        }
    }
    return answer;
}
