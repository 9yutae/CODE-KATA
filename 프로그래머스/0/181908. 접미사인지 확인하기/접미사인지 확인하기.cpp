#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
    vector<string> suffix;
    for(int i=0;i<my_string.size();i++) {
        suffix.emplace_back(my_string.substr(i));
    }
    
    auto iter = find(suffix.begin(), suffix.end(), is_suffix);
    
    return (iter != suffix.end()) ? 1 : 0;
}