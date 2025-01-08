#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto& w:myString) w = tolower(w);
    return myString;
}