#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    while(!myStr.empty()) {
        if(find(myStr.begin(), myStr.end(), 'a') == myStr.end()
          && find(myStr.begin(), myStr.end(), 'b') == myStr.end()
          && find(myStr.begin(), myStr.end(), 'c') == myStr.end()) 
            break;

        
        int idxA = find(myStr.begin(), myStr.end(), 'a') - myStr.begin();
        int idxB = find(myStr.begin(), myStr.end(), 'b') - myStr.begin();
        int idxC = find(myStr.begin(), myStr.end(), 'c') - myStr.begin();
        
        int idx = min({idxA, idxB, idxC});
        if(!myStr.substr(0, idx).empty()) answer.push_back(myStr.substr(0, idx));
        myStr = myStr.substr(idx+1);
    }
    
    if(!myStr.empty()) answer.push_back(myStr);
    if(answer.empty()) answer.push_back("EMPTY");
    
    return answer;
}