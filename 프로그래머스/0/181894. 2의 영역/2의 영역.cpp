#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    auto from = find(arr.begin(), arr.end(), 2) - arr.begin();
    auto to = find(arr.rbegin(), arr.rend(), 2) - arr.rbegin();
    
    if(from == arr.size()) answer.emplace_back(-1);
    else if(from + to == arr.size() - 1) answer.emplace_back(2);
    else copy(arr.begin() + from, arr.end() - to, back_inserter(answer));
    
    return answer;
}