#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    vector<int> nums;
    stringstream ss(s);
    string tmp;
    while(ss >> tmp) {
        nums.emplace_back(stoi(tmp));
    }
    
    string answer = to_string(*min_element(nums.begin(), nums.end()))
                    + " " + to_string(*max_element(nums.begin(), nums.end()));
    
    return answer;
}