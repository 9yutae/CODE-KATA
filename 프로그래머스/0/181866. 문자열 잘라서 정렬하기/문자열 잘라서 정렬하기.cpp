#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    while(!myString.empty()) {
        if(find(myString.begin(), myString.end(), 'x') == myString.end()) 
            break;

        
        int idx = find(myString.begin(), myString.end(), 'x') - myString.begin();
        if(!myString.substr(0, idx).empty()) answer.push_back(myString.substr(0, idx));
        myString = myString.substr(idx+1);
    }
    
    if(!myString.empty()) answer.push_back(myString);
    sort(answer.begin(), answer.end());
    
    return answer;
}