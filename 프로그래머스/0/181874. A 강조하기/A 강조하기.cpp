#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto& w:myString) {
        if(w == 'a') w -= 32;
        else if(w > 'A' && w <= 'Z') w += 32;
    }
    
    return myString;
}