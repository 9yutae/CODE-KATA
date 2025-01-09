#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    auto idx = -1;   
    while(myString.find(pat, idx+1) != string::npos) {
        idx = myString.find(pat, idx+1);
        answer++;
    }
    
    return answer;
}