#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    for(auto& w:my_string) {
        if(w == alp[0]) w-=32;
    }
    return my_string;
}