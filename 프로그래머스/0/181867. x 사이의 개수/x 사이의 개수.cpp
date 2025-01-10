#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    while(!myString.empty()) {
        if(find(myString.begin(), myString.end(), 'x') == myString.end()) 
            break;
        
        int idx = find(myString.begin(), myString.end(), 'x') - myString.begin();
        answer.push_back(idx);
        myString = myString.substr(idx+1);
    }
    
    answer.push_back(myString.size());
    
    return answer;
}