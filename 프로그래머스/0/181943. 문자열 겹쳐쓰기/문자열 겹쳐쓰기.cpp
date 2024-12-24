#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    for(int i=0;i<overwrite_string.size();i++) {
        answer[i+s] = overwrite_string[i];
    }
    // answer = my_string.replace(s,overwrite_string.size(),overwrite_string);
    
    return answer;
}