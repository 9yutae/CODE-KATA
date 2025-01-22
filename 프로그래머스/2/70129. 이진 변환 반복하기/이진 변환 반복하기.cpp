#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s != "1") {
        int cnt;
        for(auto& w:s) {
            if(w == '1') cnt++;
        }
        
        answer[0]++;
        answer[1] += s.size() - cnt;
        
        s = "";
        while(true) {
            if(cnt%2) s.append("1");
            else s.append("0");
            
            cnt /= 2;
            if(cnt == 0) break;
        }
        reverse(s.begin(), s.end());
    }
    
    return answer;
}