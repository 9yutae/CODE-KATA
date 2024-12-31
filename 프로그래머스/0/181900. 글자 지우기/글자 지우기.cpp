#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    for(auto& w:indices) {
        my_string[w] = ' ';    
    }
    
    for(auto iter=my_string.begin();iter<my_string.end();) {
        if(*iter == ' ') my_string.erase(iter);
        else iter++;
    }
    
    return my_string;
}