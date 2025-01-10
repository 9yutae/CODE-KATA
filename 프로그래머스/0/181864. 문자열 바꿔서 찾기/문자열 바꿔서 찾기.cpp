#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(auto& w:myString) {
        if(w == 'A') w++;
        else w--;
    }
    
    int answer = myString.find(pat) != string::npos ? 1 : 0;
    return  answer;
}