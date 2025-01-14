#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> vec(31);
    for(auto& w:strArr) {
        vec[w.size()]++;
    }
    
    return *max_element(vec.begin(), vec.end());
}