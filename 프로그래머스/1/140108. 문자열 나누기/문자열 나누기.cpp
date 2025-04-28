#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i=0; i < s.size(); i++) {
        if (i == s.size() - 1) {
            answer++;
            cout << i << endl;
            break;
        }
        
        int same = 1, diff = 0;
        int j = i + 1;
        
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