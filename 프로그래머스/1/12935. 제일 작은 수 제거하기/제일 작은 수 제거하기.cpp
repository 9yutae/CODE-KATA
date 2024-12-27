#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    auto iter = min_element(arr.begin(), arr.end());
    arr.erase(iter);
    
    if(arr.empty()) arr.emplace_back(-1);
    
    return arr;
}