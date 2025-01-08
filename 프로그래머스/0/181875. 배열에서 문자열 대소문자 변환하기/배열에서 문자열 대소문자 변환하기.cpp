#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for(int i=0;i<strArr.size();i++) {
        if(i%2) {
            for(auto& w:strArr[i]) w = toupper(w);
        }
        else {
            for(auto& w:strArr[i]) w = tolower(w);
        }
    }
    
    return strArr;
}