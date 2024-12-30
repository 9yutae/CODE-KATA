#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string str = my_string.substr(s, e - s + 1);
    
    for(int i=s;i<=e;i++) {
        my_string[i] = str[e-i];
    }
    
    return my_string;
}