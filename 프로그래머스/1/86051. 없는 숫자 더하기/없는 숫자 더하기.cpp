#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> nums(10);
    iota(nums.begin(), nums.end(), 0);
    
    for(const auto& w:numbers) {
        auto iter = find(nums.begin(), nums.end(), w);
        if(iter != nums.end()) nums.erase(iter);
        else iter++;
    }
    
    for(const auto& w:nums) answer += w;
    
    return answer;
}