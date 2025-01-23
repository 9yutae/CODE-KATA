#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto& w:myString) {
        if(w < 'l') w = 'l';
    }
    return myString;
}